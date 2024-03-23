#ifndef CLASS_SYSTEM_H
#define CLASS_SYSTEM_H

#include <string>
#include <vector>
#include <list>
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
    static std::list<Goods> goods;

    static int tick, money, mapid;
    
    static std::ofstream log_file, rpy_file;

    static int nearest[N][N];
    static bool nearby[c_berth_num][c_berth_num];
    static void calcNearest();

    static void Init();
    static size_t Input();

    static void Update_front();
    static void Update_back();

    static const bool __SUBMIT__ = false;

    static const bool __DEBUG__ = false && !__SUBMIT__;

    static const bool __OUTPUT_RPY__ = true && !__SUBMIT__;

    static const bool __OUTPUT_LOG__ = true && !__SUBMIT__;
    static const bool __OUTPUT_ERR__ = true;
    static const bool __OUTPUT_INFO__ = false;
    static void log(std::string type, std::string log);

    static bool mapchanged;
    static void RpyMap(bool first = false);
    static void RpyTick(int tick, bool mapChange = false);

    static int getGoods(int x, int y);
    static bool pullGoods(int x, int y, int val);

    static int skip_ticks;

    static int pull_sum;
    static int pull_value_sum;

    static int boat_trans_goods;
    static int boat_trans_val;

    static int goods_sum;
    static int goods_val;

};

#endif