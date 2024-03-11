#include "classSystem.hpp"

#include <iostream>
#include <fstream>

std::vector<Robot> System::robot;
std::vector<Boat> System::boat;
std::vector<Berth> System::berth;
std::vector<Goods> System::goods;

int System::tick = 0;
int System::money = 0;

std::ofstream System::log_file("_log.txt");

void System::Init()
{
    if (__OUTPUT_LOG__)
        std::cerr.rdbuf(log_file.rdbuf());

    // load map info
    for (size_t i = 0; i < c_size; ++ i)
        std::cin >> DisMap::ch[i];

    // load berth info
    for (size_t i = 0; i < c_berth_num; ++ i)
    {
        int id, x, y, trans_time, loading_speed;
        std::cin >> id >> x >> y >> trans_time >> loading_speed;
        // cerr << id << x << y << trans_time << loading_speed;
        System::berth.emplace_back(x, y, trans_time, loading_speed);

        // for (int x = 0; x < c_size; ++ x)
        // for (int y = 0; y < c_size; ++ y)
        // {
        //     int d = System::berth.back().dis[x][y];
        //     cerr << ((d == INT_MAX) ? -1 : d) << ((y == c_size - 1) ? "\n" : "\t");
        // }
    }

    // load boat info
    System::boat.resize(c_boat_num);
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
        System::log("ERR", "Tick " + std::to_string(System::tick) + " -> " + std::to_string(_tick));
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
        // System::goods.emplace_back(x, y, val, tick);
    }

    // load robot info
    for (size_t i = 0; i < c_robot_num; ++ i)
    {
        int goods, x, y, status;
        std::cin >> goods >> x >> y >> status;

        if (robot[i].x != x or robot[i].y != y or robot[i].goods != goods)
            System::log("ERR", robot[i].info() + "Out of sync || Current : [" + 
                    std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(goods) + "]");

        System::robot[i].x = x;
        System::robot[i].y = y;
        System::robot[i].goods = goods;
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


bool System::getGoods(int x, int y)
{
    for (auto it = goods.begin(); it != goods.end(); ++ it)
        if (it->x == x and it->y == y)
        {
            goods.erase(it);
            return true;
        }
    return false;
}

bool System::pullGoods(int x, int y)
{
    for (auto &it : berth)
        if ( it.x <= x and x < it.x + 4 and 
             it.y <= y and y < it.y + 4 )
            return true;
    return false;
}
