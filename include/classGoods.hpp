#ifndef CLASS_GOODS_H
#define CLASS_GOODS_H

#include "constList.hpp"

#include "classMap.hpp"

class Goods : public DisMap
{
public:

    Goods(int x, int y, int val, size_t tick) : x(x), y(y), val(val), creat_tick(tick), tag_select(false)
    {
        setZeroRect(x, y, 1, 1);
        creat();
    }

    int life(int tick) { return c_time_goodslife - (tick - creat_tick); }
    
    int x, y, val;

    struct Factor{
        int hp , val, dis, ber_val;
    }   factor;

    bool tag_select;

private:

    int creat_tick;

};

#endif