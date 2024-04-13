#include "classSystem.hpp"
#include "classCommand.hpp"

#include <iostream>

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <string.h>

std::vector<Robot> System::robot;
std::vector<Boat> System::boat;
std::vector<Berth> System::berth;
std::list<Goods> System::goods;

std::vector<std::pair<int, int>> System::BuyRobotPos;
std::vector<std::pair<int, int>> System::BuyBoatPos;
std::vector<std::pair<int, int>> System::deliveryPos;

int System::tick = 0;
int System::money = 0;
int System::mapid = 0;

std::ofstream System::log_file, System::rpy_file;

int System::nearest[N][N];
std::vector<std::vector<bool>> System::nearby;

static std::string GetCurrentTimeAsString() {
    // 获取当前时间
    std::time_t now = std::time(nullptr);
    std::tm* timeinfo = std::localtime(&now);

    // 格式化时间为字符串
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1) << "_"
       << std::setfill('0') << std::setw(2) << timeinfo->tm_mday << "_"
       << std::setfill('0') << std::setw(2) << timeinfo->tm_hour << "_"
       << std::setfill('0') << std::setw(2) << timeinfo->tm_min << "_"
       << std::setfill('0') << std::setw(2) << timeinfo->tm_sec;

    return ss.str();
}

void System::calcNearest()
{
    for (int x = 0; x < c_size; ++ x)
    for (int y = 0; y < c_size; ++ y)
    {
        System::nearest[x][y] = -1;
        for (int i = 0; i < System::berth.size(); ++ i)
            if (!System::berth[i].closed)
            {
                System::nearest[x][y] = i;
                break;
            }
        if (System::nearest[x][y] == -1) continue;

        for (int i = 0; i < System::berth.size(); ++ i)
            if (!System::berth[i].closed and System::berth[i].dis[x][y] < System::berth[System::nearest[x][y]].dis[x][y])
                System::nearest[x][y] = i;

        if (System::berth[System::nearest[x][y]].dis[x][y] == INT_MAX or
            System::berth[System::nearest[x][y]].closed)
            System::nearest[x][y] = -1;
    }

    System::nearby = std::vector<std::vector<bool>>(System::berth.size(), std::vector<bool>(System::berth.size(), false));
    for (size_t x = 0; x < c_size - 1; ++ x)
    for (size_t y = 0; y < c_size - 1; ++ y)
    {
        if (nearest[x][y] == -1) continue;
        if (nearest[x+1][y] != -1)
        {
            nearby[nearest[x][y]][nearest[x+1][y]] = true;
            nearby[nearest[x+1][y]][nearest[x][y]] = true;
        }
        if (nearest[x][y+1] != -1)
        {
            nearby[nearest[x][y]][nearest[x][y+1]] = true;
            nearby[nearest[x][y+1]][nearest[x][y]] = true;
        }
    }
}

void System::buyRobot(size_t id)
{
    Command::lbot(BuyRobotPos[id].first, BuyRobotPos[id].second);
}

void System::buyBoat(size_t id)
{
    Command::lboat(BuyBoatPos[id].first, BuyBoatPos[id].second);
}


void System::Init()
{
    if (__OUTPUT_LOG__)
    {
        log_file.open("_log.txt");
        std::cerr.rdbuf(log_file.rdbuf());
    }
    if (__OUTPUT_RPY__)
    {
        rpy_file.open("rpy-player\\rpy\\" + GetCurrentTimeAsString() + ".rpy");
    }

    // load map info
    // for (size_t i = 0; i < c_size; ++ i)
    //     std::cin >> DisMap::ch[i];

    for (size_t i = 0; i < c_size; ++ i)
    {
        for (size_t j = 0; j < c_size; ++ j)
            DisMap::ch[i][j] = std::cin.get();
        std::cin.get();
    }
    
    for (size_t i = 0; i < c_size; ++ i)
    for (size_t j = 0; j < c_size; ++ j)
    {
        switch (DisMap::ch[i][j])
        {
            case 'R':
                BuyRobotPos.emplace_back(i, j);
                break;
            case 'S':
                BuyBoatPos.emplace_back(i, j);
                break;
            case 'T':
                deliveryPos.emplace_back(i, j);
                break;
            
            default:
                break;
        }
    }

    // load berth info
    int berth_num;
    std::cin >> berth_num;
    for (size_t i = 0; i < berth_num; ++ i)
    {
        int id, x, y, trans_time, loading_speed;
        std::cin >> id >> x >> y >> loading_speed;
        System::berth.emplace_back(x, y, loading_speed);
        System::berth.back().id = id;

        // for (int x = 0; x < c_size; ++ x)
        // for (int y = 0; y < c_size; ++ y)
        // {
        //     int d = System::berth.back().dis[x][y];
        //     cerr << ((d == INT_MAX) ? -1 : d) << ((y == c_size - 1) ? "\n" : "");
        // }
    }

    System::calcNearest();

    RpyMap(true);

    // load boat info
    std::cin >> Boat::boat_capacity;

    // finish sign
    char okk[100]; std::cin >> okk;
    std::cout << "OK\n";
    fflush(stdout);
}

size_t System::Input()
{
    int _money, _tick;
    std::cin >> _tick >> _money;

    if (_tick != System::tick + 1)
    {
        System::log("ERR", "Tick " + std::to_string(System::tick) + " -> " + std::to_string(_tick));
        System::skip_ticks += _tick - System::tick - 1;
    }
    System::tick = _tick;

    if (_money != System::money)
        System::log("INFO", "Money changed " + std::to_string(_money - System::money) + 
                    " ||  Current : " + std::to_string(_money));
    System::money = _money;

    // load goods info
    size_t num; std::cin >> num;
    for (size_t i = 1; i <= num; ++ i)
    {
        int x, y, val;
        std::cin >> x >> y >> val;
        System::goods.emplace_back(x, y, val, tick);
        System::goods_sum ++;
        System::goods_val += val;
    }

    // load robot info
    std::cin >> num;
    while (System::robot.size() < num)
        System::robot.emplace_back();
    
    for (size_t i = 0; i < num; ++ i)
    {
        int goods_num, x, y, status;
        std::cin >> goods_num >> x >> y >> status;

        // if (robot[i].x != x or robot[i].y != y or (bool)robot[i].goods != (bool)goods)
        //     System::log("ERR", robot[i].info() + "Out of sync || Current : [" + 
        //             std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(goods) + "]");

        System::robot[i].x = x;
        System::robot[i].y = y;
        System::robot[i].status = status;
    }

    // load boat info
    std::cin >> num;
    while (System::boat.size() < num)
        System::boat.emplace_back();

    for (size_t i = 0; i < num; ++ i)
    {
        int id, goods_num, x, y, dir, status;
        std::cin >> id >> goods_num >> x >> y >> dir >> status;
        // if (boat[i].status != status or boat[i].pos != pos)
        //     cerr << id << " " << boat[i].status << " " << boat[i].pos << "\n";
        System::boat[i].status = static_cast<Boat::Status>(status);
    }

    // finish message
    char okk[100]; std::cin >> okk;
    return tick;
}

void System::Update_front()
{
    // goods disappear
    // for (auto it = System::goods.begin(); it != System::goods.end();)
    // {
    //     auto _it = it;
    //     ++ it;
    //     if (_it->life(System::tick) <= 0)
    //     {
    //         for (auto &robot : System::robot)
    //             if (&(*_it) == robot.ptrgoods)
    //             {
    //                 robot.map = nullptr;
    //                 robot.ptrgoods = nullptr;
    //             }
    //         System::goods.erase(_it);
    //     }
    // }
    // System::goods.remove_if([](Goods g){return g.life(System::tick) <= 0;});

    // ship update
    for (auto &it : System::boat)
        if (it.status == Boat::Status::loading and it.pos == -1)
        {
            System::boat_trans_goods += it.goods;
            System::boat_trans_val += it.goods_val;
            it.goods = it.goods_val = 0;
        }
}

void System::Update_back()
{
    // ship update
    for (auto &it : System::boat)
        if (it.status == Boat::Status::loading and it.pos != -1)
            for (size_t i = 1; i <= System::berth[it.pos].load_speed; ++ i)
            {
                if (System::berth[it.pos].goods.empty() or it.goods >= Boat::boat_capacity)
                    break;
                it.goods ++;
                it.goods_val += System::berth[it.pos].goods.front();
                System::berth[it.pos].goods.pop();
            } 
}

void System::log(std::string type, std::string log)
{
    if (!__OUTPUT_LOG__) return;

    if (type == "ERR" and !__OUTPUT_ERR__) return;
    if (type == "INFO" and !__OUTPUT_INFO__) return;

    if (type == "ERR") type = "ERR ";
    std::string s_tick = std::to_string(tick);
    while (s_tick.size() < std::to_string(c_time_totaltick).size())
        s_tick = " " + s_tick;

    std::cerr << "[" << s_tick << "/" << type << "] " << log << "\n";
}

bool System::mapchanged;
void System::RpyMap(bool first)
{
    if (!System::__OUTPUT_RPY__) return;

    for (int x = 0; x < c_size; ++ x)
    for (int y = 0; y < c_size; ++ y)
    {
        int d = System::nearest[x][y];
        rpy_file << (char)((d == -1 or DisMap::ch[x][y] == 'B') ? DisMap::ch[x][y] : (d + '0')) 
                 << ((y == c_size - 1) ? "\n" : "");
    }

    // berth pos
    if (first)
        for (auto it : System::berth)
            rpy_file << it.x << " " << it.y << "\n";
}

void System::RpyTick(int tick, bool mapChange)
{
    if (!System::__OUTPUT_RPY__) return;

    rpy_file << tick << " " << std::to_string(System::boat_trans_val) <<
        " " << (mapChange ? 1 : 0) << '\n';

    if (mapChange)
        System::RpyMap();

    // item goods
    rpy_file << System::goods.size() << '\n';
    for (auto it : System::goods)
    {
        rpy_file << it.x << " " << it.y << " " << it.val << " " << it.life(tick) << '\n';
    }

    //item robot
    for (auto it : System::robot)
    {
        rpy_file << it.x << " " << it.y << " " << it.goods << '\n';

        if (it.ptrgoods != nullptr)
            rpy_file << it.ptrgoods->x << " " << it.ptrgoods->y << '\n';
        else
            rpy_file << it.x << " " << it.y << '\n';

        if (it.ptrBerth != nullptr)
            rpy_file << it.ptrBerth->x << " " << it.ptrBerth->y << '\n';
        else
            rpy_file << it.x << " " << it.y << '\n';
    }
    
    //item berth
    for (auto it : System::berth)
        rpy_file << it.goods.size() << (it.id == 9 ? '\n' : ' ');
}

int System::getGoods(int x, int y)
{
    for (auto it = goods.begin(); it != goods.end(); ++ it)
        if (it->x == x and it->y == y)
        {
            int val = it->val;
            goods.erase(it);
            return val;
        }
    return 0;
}

bool System::pullGoods(int x, int y, int val)
{
    for (auto &it : berth)
        if (it.x <= x and x < it.x + 4 and 
            it.y <= y and y < it.y + 4)
            {
                it.goods.push(val);
                System::pull_sum ++;
                System::pull_value_sum += val;
                return true;
            }
    return false;
}


int System::skip_ticks = 0;


int System::pull_sum = 0;
int System::pull_value_sum = 0;


int System::boat_trans_goods = 0;
int System::boat_trans_val = 0;


int System::goods_sum = 0;
int System::goods_val = 0;
