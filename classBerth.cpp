#ifndef CLASS_BERTH_H
#define CLASS_BERTH_H

#include <limits.h>
#include "constList.cpp"

class Berth
{
public:

    Berth()
    {
        for (int x = 0; x < c_size; ++ x)
        for (int y = 0; y < c_size; ++ y)
            dis[x][y] = INT_MAX;
    }

    int x, y;
    int transport_time;
    int loading_speed;

    int dis[N][N];
};

#endif