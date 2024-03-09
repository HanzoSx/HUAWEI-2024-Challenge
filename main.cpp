#include <vector>
#include <queue>

#include <iostream>
#include <fstream>


#include "constList.hpp"
// #include "classCommand.hpp"
// #include "classMap.hpp"
// #include "classBerth.hpp"
// #include "classBoat.hpp"
// #include "classGoods.hpp"

// #include "classRobot.hpp"

using namespace std;

// Berth berth[c_berth_num + 10];
// Boat boat[10];
// vector<Robot> robot;
// vector<Goods> goods;

int money;

void _Init()
{
    int tmp[10]; char ch[210];
    //////////////////////////////////////////////////
    // load map info
    for (size_t i = 0; i < c_size; ++ i)
        cin >> ch;//, map.ch[i]);

    // load berth info
    for (size_t i = 0; i < c_berth_num; ++ i)
    {
        int id;
        cin >> id;
        cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];//, &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
    }

    // load boat info
    cin >> tmp[0];//, &Boat::boat_capacity);

    // init robot info
    // robot.resize(c_robot_num);
    // for (size_t i = 0; i < c_robot_num; ++ i)
    //     robot[i].id = i;
    //////////////////////////////////////////////////
    /*
    queue<pair<int, int> > que;
    for (size_t i = 0; i < c_berth_num; ++ i)
    {
        while (!que.empty()) que.pop();
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

    // for (int x = 0; x < c_size; ++ x)
    // for (int y = 0; y < c_size; ++ y)
    {

    } */
    //////////////////////////////////////////////////
    // finish message
    char okk[100]; cin >> okk;
    cout << "OK\n";
    fflush(stdout);
}

size_t Input()
{
    size_t id;
    cin >> id >> money;

    // load goods info
    size_t num;
    cin >> num;
    for (size_t i = 1; i <= num; ++ i)
    {
        int x, y, val;
        cin >> x >> y >> val;
        // goods.emplace_back(x, y, val);
    }

    // load robot info
    for (size_t i = 0; i < c_robot_num; ++ i)
    {
        int goods, x, y, status;
        cin >> goods >> x >> y >> status;
        // if (robot[i].x != x or robot[i].y != y)
        //     cerr << i << "  " << x << " , " << y << "   local: " << robot[i].x << " , " << robot[i].y << "\n";
        // robot[i].x = x;
        // robot[i].y = y;
        // robot[i].goods = goods;
        // robot[i].status = status;
    }

    // load boat info
    for (size_t i = 0; i < c_boat_num; ++ i)
    {
        int status, pos;
        cin >> status >> pos;/*
        if (boat[i].status != status or boat[i].pos != pos)
        {
            boat[i].status = static_cast<Boat::Status>(status);
            boat[i].pos = pos;
            // cerr << id << " " << boat[i].status << " " << boat[i].pos << "\n";
        }
        */
    }

    // finish message
    char okk[100]; cin >> okk;
    return id;
}
/*
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

    for (auto &it : robot)
        it.step(robot);

    Command::print();
}
*/
/*
struct Berth
{
    int x;
    int y;
    int transport_time;
    int loading_speed;
    Berth(){}
    Berth(int x, int y, int transport_time, int loading_speed) {
        this -> x = x;
        this -> y = y;
        this -> transport_time = transport_time;
        this -> loading_speed = loading_speed;
    }
}berth[10 + 10]; int boat_capacity;
char ch[N][N];
void Init()
{
    for(int i = 1; i <= 200; i ++)
        scanf("%s", ch[i] + 1);
    for(int i = 0; i < 10; i ++)
    {
        int id;
        scanf("%d", &id);
        scanf("%d%d%d%d", &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
    }
    scanf("%d", &boat_capacity);
    char okk[100];
    scanf("%s", okk);
    printf("OK\n");
    fflush(stdout);
}
*/

int main()
{

    // ofstream file("_log.txt");
    // streambuf *err = cerr.rdbuf(file.rdbuf());

    // solve(0);

    _Init();
    
    for (size_t tick = 1; tick <= 15000; tick ++)
    {
        Input();

        for (size_t i = 0; i < c_robot_num; ++ i)
            cout << "move " << i << " " << rand() % 4 << "\n";
        cout << "OK\n";
        fflush(stdout);

        // solve(tick);
    }

    return 0;
}
