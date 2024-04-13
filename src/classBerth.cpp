#include "classBerth.hpp"

Berth::Berth(int x, int y, int load_speed) :
x          (x),
y          (y),
load_speed (load_speed),
factor     (0),
closed     (false)
{
    setZeroRect(x, y, 4, 4);
    creat();
}