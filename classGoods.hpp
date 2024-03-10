#ifndef CLASS_GOODS_H
#define CLASS_GOODS_H

#include "constList.hpp"

#include "classMap.hpp"

class Goods
{
public:

    Goods(int x, int y, int val, size_t tick) : x(x), y(y), val(val), creat_tick(tick)
    {
        map.setZeroRect(x, y, 1, 1);
        map.creat();
    }

    int life(int tick) { return c_time_goodslife - (tick - creat_tick); }
    DisMap& getMap() { return map; }

private:

    int x, y, val;
    int creat_tick;

    DisMap map;

};

#endif