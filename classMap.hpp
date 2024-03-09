#ifndef CLASS_MAP_H
#define CLASS_MAP_H

#include "constList.hpp"

class Map
{
public:

    bool walkable(int x, int y)
    {
        return ch[x][y] != '*' and ch[x][y] != '#';
    }

    char ch[N][N];

}   map;

#endif