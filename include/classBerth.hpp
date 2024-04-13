#ifndef CLASS_BERTH_H
#define CLASS_BERTH_H

#include <limits.h>
#include <queue>

#include "constList.hpp"
#include "classMap.hpp"

class Berth : public DisMap
{
public:

    Berth(int x, int y, int load_speed);

    // system
    int id;
    int x, y, width, height;
    int load_speed;
    std::queue<int> goods;

    // solve1
    int factor;
    bool closed;

};

#endif