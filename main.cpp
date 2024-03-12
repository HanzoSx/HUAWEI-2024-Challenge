#include <vector>
#include <queue>

#include <iostream>
#include <fstream>

#include "classCommand.hpp"
#include "classSystem.hpp"

// #include "sdk.hpp"

void CalcBerthFactor()
{
    for (auto &it : System::berth)
    {
        it.factor = 0;
        for (auto &target : System::goods)
            if (it.dis[target.x][target.y] <= c_berth_dis_range)
                it.factor ++;
    }
}

void CalcGoodsFactor(int tick)
{
    for (auto &it : System::goods)
    {
        it.factor.hp = it.life(tick);
        it.factor.val = it.val;
        it.factor.dis = INT_MAX;
        for (auto &target : System::berth)
        {
            if (it.factor.dis > target.dis[it.x][it.y])
            {
                it.factor.dis = target.dis[it.x][it.y];
                it.factor.ber_val = target.factor;
            }
        }
    }
}


double function(int disRG, int hp, int val, int disGB, int ber_val)
{
    double e[5] = {-1, -1, 1, -1, 1};
    return e[0] * disRG + e[1] * hp + e[2] * val + e[3] * disGB + e[4] * ber_val;
}

void CalcRobotTarget()
{
    for (auto &it : System::robot)
    {
        if (it.map != nullptr and it.map->dis[it.x][it.y] == 0)
        {
            if (it.goods == 0) it.get();
                else it.pull();
        }
        if (!it.goods)
        {
            Goods *tmp = nullptr;
            double tmp_func = 0;
            for (auto &target : System::goods)
            {
                if (target.tag_select and
                    (it.ptrgoods == nullptr or &target != it.ptrgoods)) continue;
                double now = function(target.dis[it.x][it.y], target.factor.hp, target.factor.val, target.factor.dis, target.factor.ber_val);
                if (tmp == nullptr and target.dis[it.x][it.y] != INT_MAX or now > tmp_func)
                {
                    tmp = &target;
                    tmp_func = now;
                }
            }
            if (tmp != nullptr)
            {
                if (it.ptrgoods != nullptr)
                    it.ptrgoods->tag_select = false;
                it.setTarget(*tmp);
                it.ptrgoods = tmp;
                tmp->tag_select = true;
            }
            // else
            // {

            // }
        }
        else
        {
            Berth *tmp = nullptr;
            for (auto &target : System::berth)
            {
                if (tmp == nullptr and target.dis[it.x][it.y] or
                    tmp != nullptr and tmp->dis[it.x][it.y] > target.dis[it.x][it.y])
                {
                    tmp = &target;
                }
            }
            if (tmp != nullptr)
            {
                it.setTarget(*tmp);
                it.ptrgoods = nullptr;
            }
            // else
            // {

            // }
        }
            
    }
}

void DoBoat(int tick)
{
    for (int i = 0; i < c_boat_num ; ++ i)
    {
        if (System::boat[i].status != Boat::done) continue;
        if (System::boat[i].pos == -1)
        {
            System::boat[i].go(i * 2);
            continue; 
        }
        if (System::boat[i].goods == Boat::boat_capacity)
        {
            System::boat[i].go(-1);
            continue;
        }
        if (System::berth[System::boat[i].pos].goods.empty())
        {
            System::boat[i].go(System::boat[i].pos == i * 2 ? i * 2 + 1 : i * 2);
        }
    }

    
}

void solve(int tick)
{
    if (tick == 1)
    {
        // for (size_t i = 0; i < c_boat_num; ++ i)
        //     Command::ship(i, i);
        // for (size_t i = 0; i < c_robot_num; ++ i)
        //     System::robot[i].setTarget(System::berth[i]);
    }

    for (auto &it : System::robot)
        it.step(System::robot);

    CalcBerthFactor();
    CalcGoodsFactor(tick);
    CalcRobotTarget();
    DoBoat(tick);
    // clog << "goods_cnt = " << System::goods.size() << "\n";

}

int main()
{
    /*
    std::ofstream file("input.txt");
    file.close();
    char ch;
    while (ch = getchar())
    {
        std::ofstream file("input.txt", std::ios::app);
        file << ch;
        file.close();
        std::cout << "OK\n";
        fflush(stdout);
    }
    return 0;
    */

    std::ifstream file("input.txt");
    std::cin.rdbuf(file.rdbuf());

    // sdk_Init();
    System::Init();
    
    while (System::tick < c_time_totaltick)
    // for (int i = 1; i <= 15000; ++ i)
    {
        // sdk_Input();
        System::Input();
        System::Update_front();

        Command::clear();
        solve(System::tick);
        Command::print();

        System::Update_back();
    }

    return 0;
}
