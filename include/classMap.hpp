#ifndef CLASS_MAP_H
#define CLASS_MAP_H

#include<queue>
#include "constList.hpp"

bool walkable(int x, int y);

class DisMap
{
public:

    DisMap();

    void setZeroRect(int x, int y, int width, int height);
    void creat();

    int dis[N][N];

    static char ch[N][N];

};


#endif