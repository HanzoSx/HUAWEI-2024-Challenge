#include <algorithm>
#include <math.h>
#include <cstring>
#include <vector>

#include "classCommand.hpp"
#include "classSystem.hpp"

double solve2_Single01Problem(
    int n,
    std::vector<int> &val,
    std::vector<int> &time,
    std::vector<int> &firstt,
    std::vector<int> &ddl,
    std::vector<int> &sol
    )
{
    std::vector<int> dp(c_time_goodslife + 500, 0);
    std::vector<std::vector<int> > lst(n, std::vector<int>(c_time_goodslife + 500, 0));

    sol.clear();
    int p = 0;

    for (size_t i = 0; i < n; ++ i)
    {
        for (int t = std::min(ddl[i], 5800); t >= time[i]; -- t)
        {
            if (t > time[i])
            {
                if (dp[t - time[i]] and dp[t] < dp[t - time[i]] + val[i])
                {
                    dp[t] = dp[t - time[i]] + val[i];
                    lst[i][t] = - time[i];
                    if (dp[p] < dp[t]) p = t;
                }
            }
            else
            {
                if (firstt[i] <= ddl[i] and dp[firstt[i]] < val[i])
                {
                    dp[firstt[i]] = val[i];
                    lst[i][firstt[i]] = - firstt[i];
                    if (dp[p] < dp[firstt[i]]) p = firstt[i];
                }
            }
        }
    }
    
    int res = 0, _res = dp[p], endtime = p;
    for (int i = n - 1; i >= 0; -- i)
        if (lst[i][p] < 0)
        {
            res += val[i];
            sol.push_back(i);
            p += lst[i][p];
        }
    if (endtime == 0) return 0;
    return (double)res / 1;endtime;
}

double solve2_calcBerthValue(
    int tick,
    Berth &berth,
    std::vector<Robot*> &robot,
    std::vector<Goods*> goods,
    std::vector<Goods*> &solution
    )
{
    int c_reserve_time = 5;
    solution.clear();
    
    std::vector<int> val, time, firstt, ddl, sol, index;

    int index_r = -1;
    double res = 0;
    for (auto &robot_it : robot)
    {
        ++ index_r;
        val.clear();
        time.clear();
        firstt.clear();
        ddl.clear();

        index.clear();

        int index_g = -1;
        for (auto &goods_it : goods)
        {
            ++ index_g;
            if (index_g % robot.size() != index_r) continue;
            if (goods_it->val < 100) continue;
            int dis_G2B = berth.dis[goods_it->x][goods_it->y];
            int dis_B2R = robot_it->ptrBerth->dis[robot_it->x][robot_it->y];
            int dis_G2R = goods_it->dis[robot_it->x][robot_it->y];

            index.push_back(index_g);

            val.push_back(goods_it->val);
            time.push_back(dis_G2B * 2);
            if (!robot_it->goods)
            {
                firstt.push_back(dis_G2B + dis_G2R);
                ddl.push_back(goods_it->life(tick) + dis_G2B - c_reserve_time);
            }
            else
            {
                firstt.push_back(dis_G2B * 2);
                ddl.push_back(goods_it->life(tick) + dis_G2B - dis_B2R - c_reserve_time);
            }
        }
        res += solve2_Single01Problem(val.size(), val, time, firstt, ddl, sol);
        solution.push_back(sol.size() ? goods[index[sol.back()]] : nullptr);

        // std::sort(sol.begin(), sol.end());

        // if (sol.size() and false)
        // {
        //     int index = 0;
        //     auto p = sol.begin();
        //     for (auto goods_it = goods.begin(); goods_it != goods.end();)
        //     {
        //         if (*p == index)
        //         {
        //             goods.erase(goods_it);
        //             p ++;
        //             if (p == sol.end()) break;
        //         }
        //         else goods_it ++;
        //         index ++;
        //     }
        // }
    }
    return res;
}

Robot *trans_robot;
Berth *trans_berth;
double max_delta;
double currentValue[c_berth_num];
void solve2_calcRobot(int tick)
{
    for (auto &robot_it : System::robot)
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

    for (int i = 0; i < c_berth_num; ++ i)
        currentValue[i] = solve2_calcBerthValue(tick, System::berth[i], ptrRobot[i], ptrGoods[i], tmpSol);
    
    // for (auto &robot : System::robot)
    {
        Robot &robot = System::robot[tick % 10];
        for (auto &berth : System::berth)
        {
            if (robot.ptrBerth == &berth) continue;
            if (berth.dis[robot.x][robot.y] == INT_MAX) continue;

            std::vector<Robot*> tmpRobot_from, tmpRobot_to;
            for (auto &it : ptrRobot[robot.ptrBerth->id])
                if (it != &robot) tmpRobot_from.push_back(it);
            tmpRobot_to = ptrRobot[berth.id];
            tmpRobot_to.push_back(&robot);

            double tmpVal_from = solve2_calcBerthValue(tick, berth, tmpRobot_from, ptrGoods[robot.ptrBerth->id], tmpSol);
            double tmpVal_to = solve2_calcBerthValue(tick, berth, tmpRobot_to, ptrGoods[berth.id], tmpSol);

            double delta = tmpVal_from + tmpVal_to - (currentValue[robot.ptrBerth->id] + currentValue[berth.id]);
            if (robot.ptrBerth->closed) delta = tmpVal_to - currentValue[berth.id] + 1;
            if (delta > max_delta)
            {
                // currentValue[robot.ptrBerth->id] = tmpVal_from;
                // currentValue[berth.id] = tmpVal_to;
                // ptrRobot[robot.ptrBerth->id] = tmpRobot_from;
                // ptrRobot[berth.id] = tmpRobot_to;

                // robot.ptrBerth = &berth;
                max_delta = delta;
                trans_robot = &robot;
                trans_berth = &berth;
            }
        }
        if (max_delta > 0)
        {
            trans_robot->ptrBerth = trans_berth;
            trans_robot = nullptr;
            trans_berth = nullptr;
            max_delta = 0;
        }
    }

    for (int i = 0; i < c_berth_num; ++ i)
    {
        solve2_calcBerthValue(tick, System::berth[i], ptrRobot[i], ptrGoods[i], tmpSol);
        for (size_t j = 0; j < tmpSol.size(); ++ j)
            if (ptrRobot[i][j]->goods)
            {
                ptrRobot[i][j]->setTarget(*ptrRobot[i][j]->ptrBerth);
                ptrRobot[i][j]->ptrgoods = nullptr;
            }
            else
            {
                ptrRobot[i][j]->setTarget(*tmpSol[j]);
                ptrRobot[i][j]->ptrgoods = tmpSol[j];
            }
    }
}

void solve2_calcBoat(int tick)
{
    for (int i = 0; i < c_boat_num ; ++ i)
    {
        int left_time = (3000 - System::berth[i * 2].trans_time - System::berth[i * 2 + 1].trans_time - c_time_berth2b) / 2;
        int choice = System::berth[i * 2].trans_time > System::berth[i * 2 + 1].trans_time? 0 : 1;
        if (System::boat[i].status != Boat::done) continue;
        if (System::boat[i].pos == -1)
        {
            System::boat[i].go(i * 2 + choice);
            continue; 
        }
        int tmp = tick % 3000;
        if (tmp == 3000 - System::berth[i * 2 + 1 - choice].trans_time)
        {
            System::boat[i].go(-1);
            continue; 
        }
        if (tmp == System::berth[i * 2 + choice].trans_time + left_time)
        {
            System::boat[i].go(i * 2 + 1 - choice);
            if (tick >= 3000 * 4) System::berth[i * 2 + choice].closed = true;
            continue; 
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
                // it.ptrBerth = &System::berth[it.id];
    }

    if (tick == 12448)
        tick = 12448;

    solve2_calcRobot(tick);
    solve2_calcBoat(tick);

    for (auto &it : System::robot)
        it.step(System::robot);
}