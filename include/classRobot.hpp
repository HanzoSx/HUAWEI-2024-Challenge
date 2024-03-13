#ifndef CLASS_ROBOT_H
#define CLASS_ROBOT_H

#include <vector>
#include <string>

class System;

class DisMap;

class Goods;

class Robot
{
public:

    Robot();

    void move(int direction);
    void get();
    void pull();

    void setTarget(DisMap &map);
    void step(std::vector<Robot> &robot);

    // system
    DisMap *map;
    int id, x, y;
    int goods, status;

    // solve1
    Goods *ptrgoods;
 
private:

    std::string info();
    friend class System;

};


#endif