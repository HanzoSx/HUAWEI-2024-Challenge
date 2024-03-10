#ifndef CLASS_BERTH_H
#define CLASS_BERTH_H

#include <limits.h>
#include "constList.hpp"

#include "classMap.hpp"

class Berth
{
public:

    Berth(int x, int y, int trans_time, int load_speed) :
    x          (x),
    y          (y),
    trans_time (trans_time),
    load_speed (load_speed)
    {
        map.setZeroRect(x, y, 4, 4);
        map.creat();
    }

    int x, y;
    int trans_time, load_speed;

    DisMap& getMap() { return map; }

private:

    DisMap map;

};

#endif