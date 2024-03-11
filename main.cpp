#include <vector>
#include <queue>

#include <iostream>
#include <fstream>

#include "classCommand.hpp"

#include "classRobot.hpp"
#include "classBoat.hpp"
#include "classBerth.hpp"
#include "classGoods.hpp"

#include "classSystem.hpp"

#include "sdk.hpp"

using namespace std;

int money;

void Init()
{
    // load map info
    for (size_t i = 0; i < c_size; ++ i)
        cin >> DisMap::ch[i];

    // load berth info
    for (size_t i = 0; i < c_berth_num; ++ i)
    {
        int id, x, y, trans_time, loading_speed;
        cin >> id >> x >> y >> trans_time >> loading_speed;
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
    cin >> Boat::boat_capacity;

    // init robot info
    System::robot.resize(c_robot_num);
    for (size_t i = 0; i < c_robot_num; ++ i)
        System::robot[i].id = i;

    // finish sign
    char okk[100]; cin >> okk;
    cout << "OK\n";
    fflush(stdout);
}

size_t Input()
{
    size_t tick;
    cin >> tick >> money;

    // load goods info
    size_t num; cin >> num;
    for (size_t i = 1; i <= num; ++ i)
    {
        int x, y, val;
        cin >> x >> y >> val;
        // System::goods.emplace_back(x, y, val, tick);
    }

    // load robot info
    for (size_t i = 0; i < c_robot_num; ++ i)
    {
        int goods, x, y, status;
        cin >> goods >> x >> y >> status;
        // if (robot[i].x != x or robot[i].y != y)
        //     cerr << i << "  " << x << " , " << y << "   local: " << robot[i].x << " , " << robot[i].y << "\n";
        System::robot[i].x = x;
        System::robot[i].y = y;
        System::robot[i].goods = goods;
        System::robot[i].status = status;
    }

    // load boat info
    for (size_t i = 0; i < c_boat_num; ++ i)
    {
        int status, pos;
        cin >> status >> pos;
        // if (boat[i].status != status or boat[i].pos != pos)
        //     cerr << id << " " << boat[i].status << " " << boat[i].pos << "\n";
        System::boat[i].status = static_cast<Boat::Status>(status);
        System::boat[i].pos = pos;
    }

    // finish message
    char okk[100]; cin >> okk;
    return tick;
}

void solve(int tick)
{
    if (tick == 1)
    {
        for (size_t i = 0; i < c_boat_num; ++ i)
            Command::ship(i, i);
        for (size_t i = 0; i < c_robot_num; ++ i)
            System::robot[i].setTarget(System::berth[i]);
    }

    for (auto &it : System::robot)
        it.step(System::robot);

    for (auto it = System::goods.begin(); it != System::goods.end();)
        if ((*it).life(System::tick) <= 0)
            System::goods.erase(it);
        else
            ++ it;

    // clog << "goods_cnt = " << System::goods.size() << "\n";

}

int main()
{

    ofstream file("_log.txt");
    streambuf *err = cerr.rdbuf(file.rdbuf());

    // sdk_Init();
    Init();
    
    // while (System::tick < 15000)
    for (int i = 1; i <= 15000; ++ i)
    {
        // sdk_Input();
        int _tick = Input();
        if (_tick != System::tick + 1)
            System::log("ERR", "Tick " + std::to_string(System::tick) + " -> " + std::to_string(_tick));
        System::tick = _tick;

        Command::clear();
        solve(System::tick);
        Command::print();
    }

    return 0;
}
