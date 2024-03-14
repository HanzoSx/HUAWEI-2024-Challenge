#include <math.h>
#include <cstring>
#include <vector>

#include "classCommand.hpp"
#include "classSystem.hpp"

int solve2_Single01Problem(
    int n,
    std::vector<int> &val,
    std::vector<int> &t,
    std::vector<int> &firstt,
    std::vector<int> &ddl,
    int &finish,
    std::vector<int> &solsol
    )
{
    std::vector<int> dp(0, c_time_goodslife);
    std::vector<bool> first(c_time_goodslife);
    
}

int solve2_calcBerthValue(
    int tick,
    Berth &berth,
    std::vector<Robot*> &robot,
    std::vector<Goods*> &goods,
    std::vector<Goods*> &solution)
{
    int c_reserve_time = 5;
    solution.clear();

    // int dp[c_time_goodslife + 100];
    // Goods* sol[c_time_goodslife + 100];
    // bool first[c_time_goodslife + 100];
    // for (auto &it : robot)
    // {
    //     solution.push_back(nullptr);
    //     memset(dp, 0, sizeof dp);
    //     memset(sol, 0, sizeof sol);
    //     memset(first, false, sizeof first);

    //     int start = 0;
    //     if (it->goods) start = it->ptrBerth->dis[it->x][it->y];

    //     for (auto &goods : goods)
    //     {
    //         if (goods->life(tick) - berth.dis[goods->x][goods->y] - c_reserve_time < start) continue;

    //         for (int i = goods->life(tick) - berth.dis[goods->x][goods->y] - c_reserve_time; i > start; ++ i)
    //             if (dp[i] < dp[i - berth.dis[goods->x][goods->y] * 2] + goods->val)
    //             {
    //                 dp[i] = dp[i - berth.dis[goods->x][goods->y] * 2] + goods->val;
    //                 sol[i] = goods;
    //             }

    //         int t = berth.dis[goods->x][goods->y] + goods->dis[it->x][it->y];
    //         if (dp[t + start] < dp[start] + goods->val)
    //         {
    //             dp[t + start] = goods->val;
    //             sol[t + start] = goods;
    //             first[t + start] = true;
    //         }
    //     }

        
    // }
}

void solve2_calcRobot(int tick)
{
    std::vector<Robot*> ptrRobot[c_berth_num];
    std::vector<Goods*> ptrGoods[c_berth_num], tmpSol;
    for (int i = 0; i < c_berth_num; ++ i)
    {
        for (auto &it : System::robot)
            if (it.ptrBerth == &System::berth[i])
                ptrRobot[i].push_back(&it);

        for (auto &it : System::goods)
            if (System::nearest[it.x][it.y] == i)
                ptrGoods[i].push_back(&it);
    }

    int currentValue[c_berth_num];
    for (int i = 0; i < c_berth_num; ++ i)
        currentValue[i] = solve2_calcBerthValue(tick, System::berth[i], ptrRobot[i], ptrGoods[i], tmpSol);
    
    for (auto &robot : System::robot)
    {
        for (auto &berth : System::berth)
        {
            if (robot.ptrBerth == &berth) continue;

            std::vector<Robot*> tmpRobot_from, tmpRobot_to;
            for (auto &it : ptrRobot[robot.ptrBerth->id])
                if (it != &robot) tmpRobot_from.push_back(it);
            tmpRobot_to = ptrRobot[berth.id];
            tmpRobot_to.push_back(&robot);

            int tmpVal_from = solve2_calcBerthValue(tick, berth, tmpRobot_from, ptrGoods[robot.ptrBerth->id], tmpSol);
            int tmpVal_to = solve2_calcBerthValue(tick, berth, tmpRobot_to, ptrGoods[berth.id], tmpSol);

            if (currentValue[robot.ptrBerth->id] + currentValue[berth.id] < tmpVal_from + tmpVal_to)
            {
                currentValue[robot.ptrBerth->id] = tmpVal_from;
                currentValue[berth.id] = tmpVal_to;
                ptrRobot[robot.ptrBerth->id] = tmpRobot_from;
                ptrRobot[berth.id] = tmpRobot_to;

                robot.ptrBerth = &berth;
            }
        }
    }

    for (int i = 0; i < c_berth_num; ++ i)
    {
        solve2_calcBerthValue(tick, System::berth[i], ptrRobot[i], ptrGoods[i], tmpSol);
        for (size_t j = 0; j < tmpSol.size(); ++ j)
            if (System::robot[j].goods)
                System::robot[j].setTarget(*System::robot[j].ptrBerth);
            else
            {
                System::robot[j].setTarget(*tmpSol[j]);
            }
    }
}

void solve2_calcBoat(int tick)
{
    for (int i = 0; i < c_boat_num ; ++ i)
    {
        if (System::boat[i].pos != -1)
        {
            if (System::berth[System::boat[i].pos].trans_time + 10 >= c_time_totaltick - tick)
                System::boat[i].go(-1);
        }

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


void solve2(int tick)
{

    if (tick == 1)
    {
        for (auto &it : System::robot)
            if (System::nearest[it.x][it.y] >= 0)
                it.ptrBerth = &System::berth[System::nearest[it.x][it.y]];
    }

    solve2_calcRobot(tick);
    solve2_calcBoat(tick);

    for (auto &it : System::robot)
        it.step(System::robot);
}