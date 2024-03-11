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

    DisMap *map;
    Goods *ptrgoods;


    int id, x, y;
    int goods, status;
 
private:

    std::string info();
    friend class System;

};


#endif