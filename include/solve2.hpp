#include <algorithm>
#include <math.h>
#include <cstring>
#include <vector>

#include "classCommand.hpp"
#include "classSystem.hpp"

int solve2_Single01Problem(
    int n,
    std::vector<int> &val,
    std::vector<int> &time,
    std::vector<int> &firstt,
    std::vector<int> &ddl,
    std::vector<int> &sol
    )
{
    std::vector<int> dp(c_time_goodslife, 0), lst(c_time_goodslife, -1);
    std::vector<bool> first(c_time_goodslife, false);
    sol.clear();
    int p = 0;

    for (size_t i = 0; i < n; ++ i)
    {
        for (int t = ddl[i]; t > time[i]; -- t)
        {
            if (dp[t - time[i]] and dp[t] < dp[t - time[i]] + val[i])
            {
                dp[t] = dp[t - time[i]] + val[i];
                lst[t] = i;
                if (dp[p] < dp[t]) p = t;
            }
        }
        if (firstt[i] <= ddl[i] and dp[firstt[i]] < val[i])
        {
            dp[firstt[i]] = val[i];
            lst[firstt[i]] = i;
            first[firstt[i]] = true;
            if (dp[p] < dp[firstt[i]]) p = firstt[i];
        }
    }
    
    int res = 0;
    while (p)
    {
        res += val[lst[p]];
        sol.push_back(lst[p]);
        if (first[p]) break;
        p -= time[lst[p]];
    }
    return res;
}

int solve2_calcBerthValue(
    int tick,
    Berth berth,
    std::vector<Robot*> robot,
    std::vector<Goods*> goods,
    std::vector<Goods*> &solution
    )
{
    int c_reserve_time = 5;
    solution.clear();
    
    std::vector<int> val, time, firstt, ddl, sol;

    int res = 0;
    for (auto &robot_it : robot)
    {
        val.clear();
        time.clear();
        firstt.clear();
        ddl.clear();

        for (auto &goods_it : goods)
        {
            int dis_G2B = berth.dis[goods_it->x][goods_it->y];
            int dis_B2R = robot_it->ptrBerth->dis[robot_it->x][robot_it->y];
            int dis_G2R = goods_it->dis[robot_it->x][robot_it->y];

            val.push_back(goods_it->val);
            time.push_back(dis_G2B * 2);
            if (!robot_it->goods)
            {
                firstt.push_back(dis_G2B + dis_G2R);
                ddl.push_back(goods_it->life(tick) + dis_G2B);
            }
            else
            {
                firstt.push_back(dis_G2B * 2);
                ddl.push_back(goods_it->life(tick) + dis_G2B - dis_B2R);
            }
        }
        res += solve2_Single01Problem(goods.size(), val, time, firstt, ddl, sol);
        solution.push_back(sol.size() ? goods[sol.back()] : nullptr);

        std::sort(sol.begin(), sol.end());

        if (sol.size())
        {
            int index = 0;
            auto p = sol.begin();
            for (auto goods_it = goods.begin(); goods_it != goods.end();)
            {
                if (*p == index)
                {
                    goods.erase(goods_it);
                    p ++;
                    if (p == sol.end()) break;
                }
                else goods_it ++;
                index ++;
            }
        }
    }
    return res;
}

void solve2_calcRobot(int tick)
{
    for (auto robot_it : System::robot)
        if (robot_it.map != nullptr and robot_it.map->dis[robot_it.x][robot_it.y] == 0)
        {
            if (robot_it.goods)
                robot_it.pull();
            else
                robot_it.get();
        }

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
            if (berth.dis[robot.x][robot.y] == INT_MAX) continue;

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
            if (ptrRobot[i][j]->goods)
                ptrRobot[i][j]->setTarget(*ptrRobot[i][j]->ptrBerth);
            else
            {
                ptrRobot[i][j]->setTarget(*tmpSol[j]);
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