#include "classBoat.hpp"

#include "classCommand.hpp"

Boat::Boat() : pos(-1), status(done) {}

int Boat::boat_capacity = 0;


void Boat::go(int target)
{
    if (target == -1)
    {
        Command::go(id);
    }
    else
    {
        Command::ship(id, target);
    }
    status = Status::moving;
    pos = target;
    return;
}