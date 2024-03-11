#include "classSystem.hpp"

#include <iostream>

std::vector<Robot> System::robot;
std::vector<Boat> System::boat;
std::vector<Berth> System::berth;
std::vector<Goods> System::goods;

int System::tick;

void System::log(std::string type, std::string log)
{
    if (!__OUTPUT_LOG__) return;

    if (type == "ERR" and !__OUTPUT_ERR__) return;
    if (type == "INFO" and !__OUTPUT_INFO__) return;

    if (type == "ERR") type = "ERR ";

    std::cerr << "[" << tick << "/" << type << "]" << log << "\n";
}


bool System::getGoods(int x, int y)
{
    for (auto it = goods.begin(); it != goods.end(); ++ it)
        if (it->x == x and it->y == y)
        {
            goods.erase(it);
            return true;
        }
    return false;
}

bool System::pullGoods(int x, int y)
{
    for (auto &it : berth)
        if ( it.x <= x and x < it.x + 4 and 
             it.y <= y and y < it.y + 4 )
            return true;
    return false;
}
