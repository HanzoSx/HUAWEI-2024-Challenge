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
        for (auto it : RobotCmd) printf("%s\n", it);
    }

    static void clear()
    {
        RobotCmd.clear();
    }

    static void move(size_t id, int direcet)
    {
        RobotCmd.emplace_back(to_string(id) + " " + to_string(direcet));
    }

private:

    static vector<string> RobotCmd;

};

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
        scanf("%d%d", &boat[i].status, &boat[i].pos);
    }

    // finish message
    char okk[100]; scanf("%s", okk);
    return id;
}

int main()
{

    ofstream file("log.txt");
    streambuf *err = cerr.rdbuf(file.rdbuf());

    Init();
    
    for (size_t tick = 1; tick <= 15000; tick ++)
    {
        size_t id = Input();

        // for (size_t i = 0; i < robot_num; ++ i)
        //     printf("move %d %d\n", i, rand() % 4);

        puts("OK");
        fflush(stdout);
    }

    return 0;
}
