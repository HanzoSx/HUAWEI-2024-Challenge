#include "classRobot.hpp"

#include <vector>
#include <limits.h>

#include "constList.hpp"
#include "classCommand.hpp"
#include "classMap.hpp"
#include "classSystem.hpp"

 Robot::Robot() :
 id      (0),
 x       (0),
 y       (0),
 goods   (0),
 status  (0),
 map     (nullptr),
 ptrgoods(nullptr),
 ptrBerth(nullptr)
 {}

void Robot::move(int direction)
{
    if (direction < 0 or direction > 3)
    {
        System::log("ERR", info() + "can't move");
        return;
    }
    Command::move(id, direction);
    x += c_dir[direction][0];
    y += c_dir[direction][1];
    System::log("INFO", info() + "move [" + to_string(c_dir[direction][0]) + ", " + to_string(c_dir[direction][1]) + "]");
}

void Robot::get()
{
    if (goods)
    {
        System::log("ERR", info() + "get twice");
        return;
    }

    Command::get(id);
    if (int val = System::getGoods(x, y))
    {
        goods = val;
        map = nullptr;
        ptrgoods = nullptr;
        System::log("INFO", info() + "get");
    }
    else
        System::log("ERR", info() + "get empty");
}

void Robot::pull()
{
    if (!goods)
    {
        System::log("ERR", info() + "pull with empty");
        return;
    }

    Command::pull(id);
    if (System::pullGoods(x, y, goods))
    {
        goods = 0;
        System::log("INFO", info() + "pull");
    }
    else
        System::log("ERR", info() + "pull out of berth");
}

void Robot::setTarget(DisMap &map)
{
    this->map = &map;
    System::log("INFO", info() + "set new target");
}

void Robot::step(vector<Robot> &robot)
{
    if (ptrBerth != nullptr and ptrBerth->closed) return;
    if (map == nullptr or map->dis[x][y] == 0) return;

    int tmpDir = -1, tmpDis = INT_MAX, perturbation = x + y;
    for (int _i = 0; _i < 4; ++ _i)
    {
        int i = (_i + perturbation) % 4;
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

std::string Robot::info()
{
    return "Robot " + to_string(id) + "[" + to_string(x) + ", " + to_string(y) + ", " + to_string(goods) + "] ";
}
