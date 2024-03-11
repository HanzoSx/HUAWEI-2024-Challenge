#ifndef CLASS_SYSTEM_H
#define CLASS_SYSTEM_H

#include <string>
#include <vector>
#include <fstream>

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

    static int tick, money;
    
    static std::ofstream log_file;

    static void Init();
    static size_t Input();

    static const bool __OUTPUT_LOG__ = true;
    static const bool __OUTPUT_ERR__ = true;
    static const bool __OUTPUT_INFO__ = true;
    static void log(std::string type, std::string log);

    static bool getGoods(int x, int y);
    static bool pullGoods(int x, int y);


};

#endif