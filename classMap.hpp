#ifndef CLASS_MAP_H
#define CLASS_MAP_H

#include "constList.hpp"

char ch[N][N];
bool walkable(int x, int y)
{
    return ch[x][y] != '*' and ch[x][y] != '#';
}

class DisMap
{
public:

    DisMap();

    void setZeroRect(int x, int y, int width, int height);
    void creat();

    int dis[N][N];

};

DisMap::DisMap()
{
    for (int x = 0; x < c_size; ++ x)
    for (int y = 0; y < c_size; ++ y)
        dis[x][y] = INT_MAX;
}

void DisMap::setZeroRect(int x, int y, int width, int height)
{
    for (int dx = x; dx < x + width; ++ dx)
    for (int dy = x; dy < x + height; ++ dy)
        dis[dx][dy] = 0;
}

void DisMap::creat()
{
    
}


#endif