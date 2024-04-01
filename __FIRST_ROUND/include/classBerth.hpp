#ifndef CLASS_BERTH_H
#define CLASS_BERTH_H

#include <limits.h>
#include <queue>

#include "constList.hpp"
#include "classMap.hpp"

class Berth : public DisMap
{
public:

    Berth(int x, int y, int trans_time, int load_speed);

    // system
    int x, y, id;
    int trans_time, load_speed;
    std::queue<int> goods;

    // solve1
    int factor;
    bool closed;

};

#endif