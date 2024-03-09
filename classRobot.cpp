#ifndef CLASS_ROBOT_H
#define CLASS_ROBOT_H

#include <vector>

#include <limits.h>
#include "classCommand.cpp"
#include "classMap.cpp"
#include "constList.cpp"
#include "classBerth.cpp"
#include "classGoods.cpp"

using namespace std;

class Robot
{
public:

    Robot() {}
    Robot(int startX, int startY) : x(startX), y(startY) {}


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
        Berth *berth;
        int distence;
    };

    union
    {
        GetInfo get;
        PullInfo pull;
    };

    void setPull(Berth& berth, int distence);
    void setGet(Goods& goods);
    void step(vector<Robot> &robot);

    int id, status;
    int x, y, goods;

};

void Robot::setPull(Berth& berth, int distence)
{
    work = Work::Pull;
    pull.berth = &berth;
    pull.distence = distence;
}

void Robot::setGet(Goods& goods)
{
    work = Work::Get;
}

void Robot::step(vector<Robot> &robot)
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

                for (auto &other : robot)
                    if (other.x == dx and other.y == dy)
                    {
                        f = false;
                        break;
                    }
                if (!map.walkable(dx, dy))
                    f = false;
                
                if (f and pull.berth->dis[dx][dy] < tmpDis)
                {
                    tmpDir = i;
                    tmpDis = pull.berth->dis[dx][dy];
                }
            }

            if (tmpDir > -1)
            {
                Command::move(id, tmpDir);
                x += c_dir[tmpDir][0];
                y += c_dir[tmpDir][1];
            }
            break;
        }
        
        default:
            break;
    }
}



#endif