#ifndef CLASS_BOAT_H
#define CLASS_BOAT_H

class Boat
{
public:

    Boat();

    static int boat_capacity;

    void go(int target);

    int id, pos;
    enum Status
    {
        moving = 0,
        done,
        wait
    }   status;

    int goods;

};

#endif