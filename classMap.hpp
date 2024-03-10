#ifndef CLASS_MAP_H
#define CLASS_MAP_H

#include<queue>
#include "constList.hpp"
char ch[N][N];
bool walkable(int x, int y)
{
    return x >= 0 and x < c_size and y>0 and y<c_size and ch[x][y] != '*' and ch[x][y] != '#';
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
    pair<int, int> t;
    int x, y;
    queue < pair<int, int> > Q;
    for (int x = 0; x < c_size; ++ x)
    for (int y = 0; y < c_size; ++ y)
        if (dis[x][y] == 0)
            Q.push(make_pair(x, y));
    while (!Q.empty())
    {
        t=Q.front();
        Q.pop();
        x=t.first;
        y=t.second;
        for (int i = 0; i < 4; ++ i)
            if (walkable(x + c_dir[i][0], y + c_dir[i][1]) and dis[x][y] + 1 < dis[x + c_dir[i][0]][y + c_dir[i][1]])
            {
                Q.push(make_pair(x + c_dir[i][0], y + c_dir[i][1]));
                dis[x + c_dir[i][0]][y + c_dir[i][1]] = dis[x][y] + 1;
            }
    }
}


#endif