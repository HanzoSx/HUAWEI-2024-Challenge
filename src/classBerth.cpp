#include <classBerth.hpp>

Berth::Berth(int x, int y, int trans_time, int load_speed) :
x          (x),
y          (y),
trans_time (trans_time),
load_speed (load_speed)
{
    setZeroRect(x, y, 4, 4);
    creat();
}