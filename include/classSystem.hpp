#ifndef CLASS_SYSTEM_H
#define CLASS_SYSTEM_H

#include <string>
#include <vector>

#include "classRobot.hpp"
#include "classBoat.hpp"
#include "classBerth.hpp"
#include "classGoods.hpp"

class System
{
public:
    
    static std::vector<Robot> robot;
    static std::vector<Boat> boat;
    static std::vector<Berth> berth;
    static std::vector<Goods> goods;

    static int tick;
    
    static const bool __OUTPUT_LOG__ = true;
    static const bool __OUTPUT_ERR__ = true;
    static const bool __OUTPUT_INFO__ = false;
    static void log(std::string type, std::string log);

    static bool getGoods(int x, int y);
    static bool pullGoods(int x, int y);


};

#endif