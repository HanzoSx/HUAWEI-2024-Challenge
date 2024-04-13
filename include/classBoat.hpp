#ifndef CLASS_BOAT_H
#define CLASS_BOAT_H

class Boat
{
public:

    Boat();

    static int boat_capacity;

    void dept();
    void berth();
    void rot(int directon);
    void ship();

    enum Status
    {
        moving = 0,
        recover,
        loading
    }   status;

    int id, pos;
    int goods, goods_val;

};

#endif