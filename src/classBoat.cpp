#include "classBoat.hpp"

#include "classCommand.hpp"

Boat::Boat() : pos(-1), status(moving), goods(0), goods_val(0) {}

int Boat::boat_capacity = 0;

void Boat::dept()
{
    Command::dept(this->id);
}

void Boat::berth()
{
    Command::berth(this->id);
}

void Boat::rot(int directon)
{
    Command::rot(this->id, directon);
}

void Boat::ship()
{
    Command::ship(this->id);
}

