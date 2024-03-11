#include "classMap.hpp"

#include <limits.h>

bool walkable(int x, int y)
{
    return x >= 0 and x < c_size and y >= 0 and y < c_size and
        DisMap::ch[x][y] != '*' and DisMap::ch[x][y] != '#';
}

DisMap::DisMap()
{
    for (int x = 0; x < c_size; ++ x)
    for (int y = 0; y < c_size; ++ y)
        dis[x][y] = INT_MAX;
}

void DisMap::setZeroRect(int x, int y, int width, int height)
{
    zeroRect = {x, y, width, height};
    for (int dx = x; dx < x + width; ++ dx)
    for (int dy = y; dy < y + height; ++ dy)
        dis[dx][dy] = 0;
}

void DisMap::creat()
{
    std::queue < std::pair<int, int> > Q;
    for (int x = zeroRect.x; x < zeroRect.x + zeroRect.width; ++ x)
    for (int y = zeroRect.y; y < zeroRect.y + zeroRect.height; ++ y)
        if (dis[x][y] == 0)
            Q.push(std::make_pair(x, y));

    while (!Q.empty())
    {
        auto [x, y] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; ++ i)
            if (walkable(x + c_dir[i][0], y + c_dir[i][1]) and
                dis[x][y] + 1 < dis[x + c_dir[i][0]][y + c_dir[i][1]])
            {
                Q.push(std::make_pair(x + c_dir[i][0], y + c_dir[i][1]));
                dis[x + c_dir[i][0]][y + c_dir[i][1]] = dis[x][y] + 1;
            }
    }
}

char DisMap::ch[N][N];
