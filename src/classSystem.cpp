#include "classSystem.hpp"

#include <iostream>

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

std::vector<Robot> System::robot;
std::vector<Boat> System::boat;
std::vector<Berth> System::berth;
std::list<Goods> System::goods;

int System::tick = 0;
int System::money = 0;

std::ofstream System::log_file, System::rpy_file;

int System::nearest[N][N];

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
    for (size_t i = 0; i < c_size; ++ i)
        std::cin >> DisMap::ch[i];

    // load berth info
    for (size_t i = 0; i < c_berth_num; ++ i)
    {
        int id, x, y, trans_time, loading_speed;
        std::cin >> id >> x >> y >> trans_time >> loading_speed;
        System::berth.emplace_back(x, y, trans_time, loading_speed);
        System::berth.back().id = i;

        // for (int x = 0; x < c_size; ++ x)
        // for (int y = 0; y < c_size; ++ y)
        // {
        //     int d = System::berth.back().dis[x][y];
        //     cerr << ((d == INT_MAX) ? -1 : d) << ((y == c_size - 1) ? "\n" : "");
        // }
    }

    for (int x = 0; x < c_size; ++ x)
    for (int y = 0; y < c_size; ++ y)
    {
        System::nearest[x][y] = 0;
        for (int i = 0; i < c_berth_num; ++ i)
            if (System::berth[i].dis[x][y] < System::berth[System::nearest[x][y]].dis[x][y])
                System::nearest[x][y] = i;

        if (System::berth[System::nearest[x][y]].dis[x][y] == INT_MAX)
            System::nearest[x][y] = -1;
    }

    RpyMap();

    // load boat info
    System::boat.resize(c_boat_num);
    for (size_t i = 0; i < c_boat_num; ++ i)
        System::boat[i].id = i;
    std::cin >> Boat::boat_capacity;

    // init robot info
    System::robot.resize(c_robot_num);
    for (size_t i = 0; i < c_robot_num; ++ i)
        System::robot[i].id = i;

    // finish sign
    char okk[100]; std::cin >> okk;
    std::cout << "OK\n";
    fflush(stdout);
}

size_t System::Input()
{
    int _tick, _money;
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
    for (size_t i = 0; i < c_robot_num; ++ i)
    {
        int goods, x, y, status;
        std::cin >> goods >> x >> y >> status;

        if (robot[i].x != x or robot[i].y != y or (bool)robot[i].goods != (bool)goods)
            System::log("ERR", robot[i].info() + "Out of sync || Current : [" + 
                    std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(goods) + "]");

        System::robot[i].x = x;
        System::robot[i].y = y;
        System::robot[i].status = status;
    }

    // load boat info
    for (size_t i = 0; i < c_boat_num; ++ i)
    {
        int status, pos;
        std::cin >> status >> pos;
        // if (boat[i].status != status or boat[i].pos != pos)
        //     cerr << id << " " << boat[i].status << " " << boat[i].pos << "\n";
        System::boat[i].status = static_cast<Boat::Status>(status);
        System::boat[i].pos = pos;
    }

    // finish message
    char okk[100]; std::cin >> okk;
    return tick;
}

void System::Update_front()
{
    // goods disappear
    for (auto it = System::goods.begin(); it != System::goods.end();)
    {
        auto _it = it;
        ++ it;
        if (_it->life(System::tick) <= 0)
        {
            if (_it->tag_select)
            {
                for (auto &robot : System::robot)
                    if (&(*_it) == robot.ptrgoods)
                    {
                        robot.map = nullptr;
                        robot.ptrgoods = nullptr;
                    }
            }
            System::goods.erase(_it);
        }
    }
    // System::goods.remove_if([](Goods g){return g.life(System::tick) <= 0;});

    // ship update
    for (auto &it : System::boat)
        if (it.status == Boat::Status::done and it.pos == -1)
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
        if (it.status == Boat::Status::done and it.pos != -1)
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

void System::RpyMap()
{
    if (!System::__OUTPUT_RPY__) return;

    for (int x = 0; x < c_size; ++ x)
    for (int y = 0; y < c_size; ++ y)
    {
        int d = System::nearest[x][y];
        rpy_file << (char)((d == -1 or DisMap::ch[x][y] == 'B') ? DisMap::ch[x][y] : (d + '0')) 
                 << ((y == c_size - 1) ? "\n" : "");
    }
}

void System::RpyTick(int tick)
{
    if (!System::__OUTPUT_RPY__) return;

    rpy_file << tick << " " << std::to_string(System::boat_trans_val) << '\n';

    // item goods
    rpy_file << System::goods.size() << '\n';
    for (auto it : System::goods)
    {
        rpy_file << it.x << " " << it.y << " " << it.val << '\n';
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
