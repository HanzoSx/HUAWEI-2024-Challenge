#ifndef CLASS_BOAT_H
#define CLASS_BOAT_H

struct Boat
{
    Boat() : num(0), pos(-1), status(done) {}

    int num, pos;
    enum Status
    {
        moving = 0,
        done,
        wait
    }   status;

    static int boat_capacity;
};
int Boat::boat_capacity = 0;

#endif