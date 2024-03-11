#ifndef CLASS_ROBOT_H
#define CLASS_ROBOT_H

#include <vector>
#include <string>

class DisMap;

class Robot
{
public:

    Robot() : map(nullptr) {}

    void move(int direction);
    void get();
    void pull();

    void setTarget(DisMap &map);
    void step(std::vector<Robot> &robot);

    DisMap *map;

    int id, x, y;
    int goods, status;

private:

    std::string info();

};


#endif