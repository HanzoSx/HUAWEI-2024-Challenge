#include <math.h>

#include "classCommand.hpp"
#include "classSystem.hpp"

void solve3(int tick)
{

    if (tick == 1)
    {
        for (auto &goods : System::goods)
            for (auto &robot : System::robot)
                if (goods.dis[robot.x][robot.y] != INT_MAX and robot.map == nullptr)
                {
                    robot.setTarget(goods);
                    robot.ptrgoods = &goods;
                    break;
                }
    }

    for (auto &it : System::robot)
        it.step(System::robot);
}