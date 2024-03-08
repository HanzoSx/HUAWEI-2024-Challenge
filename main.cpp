#include <vector>
#include <queue>

#include <iostream>
#include <fstream>

using namespace std;

const int c_dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

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

struct Berth
{
    Berth()
    {
        for (int x = 0; x < c_size; ++ x)
        for (int y = 0; y < c_size; ++ y)
            dis[x][y] = INT_MAX;
    }

    int x, y;
    int transport_time;
    int loading_speed;

    int dis[N][N];
};
Berth berth[c_berth_num + 10];

struct Robot
{
    Robot() {}
    Robot(int startX, int startY) : x(startX), y(startY) {}

    int id, status;
    int x, y, goods;

    enum Work
    {
        Get = 0,
        Pull
    };
    Work work;

    struct GetInfo
    {
        int x, y;
        // vector<pair<int, int> > path;
    };

    struct PullInfo
    {
        int berth_id, distence;
    };

    union
    {
        GetInfo get;
        PullInfo pull;
    };

    void setPull(int berth_id, int distence)
    {
        work = Work::Pull;
        pull.berth_id = berth_id;
        pull.distence = distence;
    }

    void setGet(int x, int y)
    {

    }

    void step();

};
Robot robot[c_robot_num + 10];

void Robot::step()
{
    switch (work)
    {
        case Work::Pull:
        {
            int tmpDir = -1, tmpDis = INT_MAX;
            for (int i = 0; i < 4; ++ i)
            {
                int dx = x + c_dir[i][0], dy = y + c_dir[i][1];

                bool f = true;
                for (size_t index = 0; index < c_robot_num; ++ index)
                    if (robot[index].x == dx and robot[index].y == dy)
                    {
                        f = false;
                        break;
                    }

                if (map_ch[dx][dy] == '*' or map_ch[dx][dy] == '#')
                    f = false;
                
                if (f and berth[pull.berth_id].dis[dx][dy] < tmpDis)
                {
                    tmpDir = i;
                    tmpDis = berth[pull.berth_id].dis[dx][dy];
                }
            }

            if (tmpDir > -1)
            {
                Command::move(id, tmpDir);
                x += c_dir[id][0];
                y += c_dir[id][1];
            }
            break;
        }
        
        default:
            break;
    }
}

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

Boat boat[10];
vector<Goods> goods;

int money;

void Init()
{
    //////////////////////////////////////////////////
    // load map info
    for (size_t i = 0; i < c_size; ++ i)
        scanf("%s", map_ch[i]);

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
                int dx = c_dir[j][0], dy = c_dir[j][1];
                if (map_ch[x + dx][y + dy] == '*' or map_ch[x + dx][y + dy] == '#')
                    continue;
                if (berth[i].dis[x + dx][y + dy] > berth[i].dis[x][y] + 1)
                {
                    berth[i].dis[x + dx][y + dy] = berth[i].dis[x][y] + 1;
                    que.push(make_pair<int, int>(x + dx, y + dy));
                }
            }
        }

        for (size_t x = 0; x < c_size; ++ x)
        for (size_t y = 0; y < c_size; ++ y)
            cerr << ((berth[i].dis[x][y] == INT_MAX) ? -1 : berth[i].dis[x][y]) << ((y == c_size - 1) ? '\n' : '\t');
        
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

    if (tick == 1)
    {
        for (size_t i = 0; i < c_boat_num; ++ i)
            Command::ship(i, i);
        for (size_t i = 0; i < c_robot_num; ++ i)
            robot[i].setPull(i, 0);
    }

    for (size_t i = 0; i < c_robot_num; ++ i)
    {
        robot[i].step();
    }

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
