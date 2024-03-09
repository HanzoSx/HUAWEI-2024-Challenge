#ifndef CLASS_GOODS_H
#define CLASS_GOODS_H

#include "constList.hpp"

class Goods
{
public:

    Goods() : life(c_time_goodslife) {}
    Goods(int x, int y, int val) : x(x), y(y), val(val), life(c_time_goodslife) {}

private:

    int x, y, val;
    int life;

};

#endif