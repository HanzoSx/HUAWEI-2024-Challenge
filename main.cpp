#include <vector>

#include <iostream>
#include <fstream>

using namespace std;

const int c_size = 200;
const int c_robot_num = 10;
const int c_berth_num = 10;
const int c_boat_num = 5;

const int c_time_berth2b = 500;
const int c_time_goodslife = 1000;

const int N = c_size + 10;
char map_ch[N][N];

class Command
{
public:

    static void print()
    {
        for (auto& it : RobotCmd) printf("%s\n", it.c_str());
        for (auto& it : BoatCmd) printf("%s\n", it.c_str());
        
        printf("OK\n");
        fflush(stdout);
    }

    static void clear()
    {
        RobotCmd.clear();
        BoatCmd.clear();
    }

    static void move(size_t id, int direcet)  { RobotCmd.emplace_back("move " + to_string(id) + " " + to_string(direcet)); }
    static void get(size_t id)                { RobotCmd.emplace_back("get " + to_string(id)); }
    static void pull(size_t id)               { RobotCmd.emplace_back("pull " + to_string(id)); }

    static void ship(size_t id, int berth_id) { BoatCmd.emplace_back("ship " + to_string(id) + " " + to_string(berth_id)); }
    static void go(size_t id)                 { BoatCmd.emplace_back("go " + to_string(id)); }

private:

    static vector<string> RobotCmd, BoatCmd;

};
vector<string> Command::RobotCmd, Command::BoatCmd;


struct Robot
{
    Robot() {}
    Robot(int startX, int startY) : x(startX), y(startY) {}

    int status;
    int x, y, goods;
};

struct Berth
{
    Berth() {}

    int x, y;
    int transport_time;
    int loading_speed;
};

struct Boat
{
    Boat() : num(0), pos(-1), status(done) {}

    int num, pos;
    enum Status
    {
        moving = 0,
        done,
        wait
    }   status;

    static int boat_capacity;
};
int Boat::boat_capacity = 0;

struct Goods
{
    Goods() : life(c_time_goodslife) {}
    Goods(int x, int y, int val) : x(x), y(y), val(val), life(c_time_goodslife) {}

    int x, y, val;
    int life;
};

Robot robot[c_robot_num + 10];
Berth berth[c_berth_num + 10];
Boat boat[10];
vector<Goods> goods;

int money;

void Init()
{
    // load map info
    for (size_t i = 1; i <= c_size; ++ i)
        scanf("%s", map_ch[i] + 1);

    // load berth info
    for (size_t i = 0; i < c_berth_num; ++ i)
    {
        int id;
        scanf("%d", &id);
        scanf("%d%d%d%d", &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
    }

    // load boat info
    scanf("%d", &Boat::boat_capacity);

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
        scanf("%d%d%d%d", &robot[i].goods, &robot[i].x, &robot[i].y, &robot[i].status);
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
            cerr << id << " " << boat[i].status << " " << boat[i].pos << "\n";
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

    if (tick == 10)
    {
        for (size_t i = 0; i < c_boat_num; ++ i)
            Command::ship(i, i + 5);
        cerr << "go +5 " << tick << "\n";
    }
    else if (tick == 2000)
    {
        for (size_t i = 0; i < c_boat_num; ++ i)
            Command::ship(i, i);
        cerr << "go +0 " << tick << "\n";
    }

    Command::print();
}

int main()
{

    // ofstream file("log.txt");
    // streambuf *err = cerr.rdbuf(file.rdbuf());

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
/*
114 199346
2
1 5 20
5 7 30
0 1 2 1
1 100 150 1
1 95 174 1
0 14 156 1
0 154 47 0
1 17 41 0
1 99 152 1
1 92 175 1
0 13 152 1
0 152 41 0
1 16 73 0
1 2
1 1
0 6
1 -1
0 8

*/