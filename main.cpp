#include <vector>
#include <queue>

#include <iostream>
#include <fstream>

#include "constList.hpp"

#include "classCommand.hpp"
#include "classMap.hpp"

#include "classBerth.hpp"
#include "classBoat.hpp"
#include "classGoods.hpp"

#include "classRobot.cpp"

using namespace std;

Berth berth[c_berth_num + 10];
Boat boat[10];
vector<Robot> robot;
vector<Goods> goods;

int money;

void Init()
{
    //////////////////////////////////////////////////
    // load map info
    for (size_t i = 0; i < c_size; ++ i)
        scanf("%s", map.ch[i]);

    // load berth info
    for (size_t i = 0; i < c_berth_num; ++ i)
    {
        int id;
        scanf("%d", &id);
        scanf("%d%d%d%d", &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
    }

    // load boat info
    scanf("%d", &Boat::boat_capacity);

    // init robot info
    robot.resize(c_robot_num);
    for (size_t i = 0; i < c_robot_num; ++ i)
        robot[i].id = i;
    //////////////////////////////////////////////////
    queue<pair<int, int> > que;
    for (size_t i = 0; i < c_berth_num; ++ i)
    {
        for (int dx = 0; dx < 4; ++ dx)
        for (int dy = 0; dy < 4; ++ dy)
        {
            berth[i].dis[berth[i].x + dx][berth[i].y + dy] = 0;
            que.push(make_pair<int, int>(berth[i].x + dx, berth[i].y + dy));
        }

        while (!que.empty())
        {
            auto [x, y] = que.front(); que.pop();
            for (int j = 0; j < 4; ++ j)
            {
                int dx = x + c_dir[j][0], dy = y + c_dir[j][1];
                if (!map.walkable(dx, dy)) continue;
                if (berth[i].dis[dx][dy] > berth[i].dis[x][y] + 1)
                {
                    berth[i].dis[dx][dy] = berth[i].dis[x][y] + 1;
                    que.push(make_pair<int, int>(0 + dx, 0 + dy));
                }
            }
        }

        // for (size_t x = 0; x < c_size; ++ x)
        // for (size_t y = 0; y < c_size; ++ y)
        //     cerr << ((berth[i].dis[x][y] == INT_MAX) ? -1 : berth[i].dis[x][y]) << ((y == c_size - 1) ? '\n' : '\t');
        
    }
    //////////////////////////////////////////////////
    // finish message
    char okk[100]; scanf("%s", okk);
    printf("OK\n");
    fflush(stdout);
}

size_t Input()
{
    size_t id;
    scanf("%d%d", &id, &money);

    // load goods info
    size_t num;
    scanf("%d", &num);
    for (size_t i = 1; i <= num; ++ i)
    {
        int x, y, val;
        scanf("%d%d%d", &x, &y, &val);
        goods.emplace_back(x, y, val);
    }

    // load robot info
    for (size_t i = 0; i < c_robot_num; ++ i)
    {
        int goods, x, y, status;
        scanf("%d%d%d%d", &goods, &x, &y, &status);
        if (robot[i].x != x or robot[i].y != y)
            cerr << i << "  " << x << " , " << y << "   local: " << robot[i].x << " , " << robot[i].y << "\n";
        robot[i].goods = goods;
        robot[i].x = x;
        robot[i].y = y;
        robot[i].status = status;
    }

    // load boat info
    for (size_t i = 0; i < c_boat_num; ++ i)
    {
        int status, pos;
        scanf("%d%d\n", &status, &pos);
        if (boat[i].status != status or boat[i].pos != pos)
        {
            boat[i].status = static_cast<Boat::Status>(status);
            boat[i].pos = pos;
            // cerr << id << " " << boat[i].status << " " << boat[i].pos << "\n";
        }
    }

    // finish message
    char okk[100]; scanf("%s", okk);
    return id;
}

void solve(int tick)
{
    // cerr << "sovle " << tick << "\n";
    Command::clear();

    if (tick == 1)
    {
        for (size_t i = 0; i < c_boat_num; ++ i)
            Command::ship(i, i);
        for (size_t i = 0; i < c_robot_num; ++ i)
            robot[i].setPull(berth[i], 0);
    }

    for (auto it : robot)
        it.step(robot);

    Command::print();
}

int main()
{

    ofstream file("log.txt");
    streambuf *err = cerr.rdbuf(file.rdbuf());

    // solve(0);

    Init();
    
    for (size_t tick = 1; tick <= 15000; tick ++)
    {
        Input();

        // for (size_t i = 0; i < c_robot_num; ++ i)
        //     printf("move %d %d\n", i, rand() % 4);

        solve(tick);
    }

    return 0;
}
