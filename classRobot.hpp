#ifndef CLASS_ROBOT_H
#define CLASS_ROBOT_H

#include <vector>

#include "constList.hpp"
#include "classBerth.hpp"
#include "classGoods.hpp"

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



#endif