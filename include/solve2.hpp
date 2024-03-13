#include <math.h>

#include "classCommand.hpp"
#include "classSystem.hpp"


void solve2_calcRobot()
{
    for (int i = 1; i < c_berth_num; ++ i)
    {
        
    }
}

void solve2_calcBoat()
{

}


void solve1(int tick)
{

    solve2_calcRobot();
    solve2_calcBoat();

    for (auto &it : System::robot)
        it.step(System::robot);
}