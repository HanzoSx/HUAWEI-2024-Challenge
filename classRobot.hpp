#ifndef CLASS_ROBOT_H
#define CLASS_ROBOT_H

#include <vector>
#include <limits.h>

#include "constList.hpp"

#include "classCommand.hpp"
#include "classMap.hpp"

using namespace std;

class Robot
{
public:

    Robot() : map(nullptr) {}

    void move(int direction);
    void get();
    void pull();

    void setDisMap(DisMap &map);
    void step(vector<Robot> &robot);

    DisMap *map;

    int id, status, x, y, goods;

};

void Robot::move(int direction)
{
    if (direction < 0 or direction > 3) return;
    Command::move(id, direction);
    x += c_dir[id][0];
    y += c_dir[id][1];
}

void Robot::get()
{
    Command::get(id);
}

void Robot::pull()
{
    Command::pull(id);
}

void Robot::setDisMap(DisMap &map)
{
    this->map = &map;
}

void Robot::step(vector<Robot> &robot)
{
    if (map == nullptr or map->dis[x][y] == 0) return;

    int tmpDir = -1, tmpDis = INT_MAX;
    for (int i = 0; i < 4; ++ i)
    {
        int dx = x + c_dir[i][0], dy = y + c_dir[i][1];

        bool f = true;

        for (auto &other : robot)
            if (other.x == dx and other.y == dy)
            {
                f = false;
                break;
            }
        if (!walkable(dx, dy)) f = false;
        
        if (f and map->dis[dx][dy] < tmpDis)
        {
            tmpDir = i;
            tmpDis = map->dis[dx][dy];
        }
    }
    move(tmpDir);
}


#endif