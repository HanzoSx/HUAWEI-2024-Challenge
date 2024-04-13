#include <algorithm>
#include <math.h>
#include <cstring>
#include <vector>

#include "classCommand.hpp"
#include "classSystem.hpp"
// #include "solve1.hpp"

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
        for (int t = std::min(ddl[i], (System::mapid == 1 ? 1600 : 1950)); t > time[i]; -- t)
            if (dp[t - time[i]] and dp[t] < dp[t - time[i]] + val[i])
            {
                dp[t] = dp[t - time[i]] + val[i];
                lst[i][t] = - time[i];
                if (dp[p] < dp[t] or dp[p] == dp[t] and t < p) p = t;
            }
                
        if (firstt[i] <= ddl[i] and dp[firstt[i]] < val[i])
        {
            dp[firstt[i]] = val[i];
            lst[i][firstt[i]] = - firstt[i];
            if (dp[p] < dp[firstt[i]] or dp[p] == dp[firstt[i]] and firstt[i] < p) p = firstt[i];
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
    
    struct Data { int val, time, firstt, ddl, index; };
    std::vector<Data> data;
    
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
        data.clear();

        int index_g = -1;
        for (auto &goods_it : goods)
        {
            ++ index_g;
            if (index_g % robot.size() != index_r) continue;
            if (goods_it->val < 100) continue;
            int dis_G2B = berth.dis[goods_it->x][goods_it->y];
            int dis_B2R = robot_it->ptrBerth->dis[robot_it->x][robot_it->y];
            int dis_G2R = goods_it->dis[robot_it->x][robot_it->y];

            data.push_back(Data());
            data.back().index = index_g;

            data.back().val = goods_it->val;
            data.back().time = dis_G2B * 2;
            if (robot_it->ptrgoods == nullptr and robot_it->goods == 0)
            {
                data.back().firstt = dis_G2B + dis_G2R;
                data.back().ddl = goods_it->life(tick) + dis_G2B - c_reserve_time;
            }
            else
            {
                data.back().firstt = dis_G2B * 2;
                data.back().ddl = goods_it->life(tick) + dis_G2B - c_reserve_time
                                  - (robot_it->ptrgoods == nullptr ?
                                    dis_B2R :
                                    robot_it->ptrgoods->dis[robot_it->x][robot_it->y] + 
                                    robot_it->ptrBerth->dis[robot_it->ptrgoods->x][robot_it->ptrgoods->y]);
            }
        }

        std::sort(data.begin(), data.end(), [](Data arg1, Data arg2){ return arg1.ddl < arg2.ddl; });
        for (auto it : data)
        {
            val.push_back(it.val);
            time.push_back(it.time);
            firstt.push_back(it.firstt);
            ddl.push_back(it.ddl);
            index.push_back(it.index);
        }

        res += robot_it->goods;
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

Berth *trans_berth;
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

    if (System::mapid == 1)
    {
        int tmp[5] = {1, 2, 6, 8, 9};
        for (auto &robot : System::robot)
            robot.ptrBerth = &System::berth[tmp[robot.id / 2]];
    }

    if (System::mapid == 1 and tick >= 1000)// or System::mapid == 0 and tick >= 13500)
    {
        for (auto &robot : System::robot)
        {
            if (robot.goods) robot.setTarget(*robot.ptrBerth);
            if (robot.goods or robot.ptrgoods != nullptr) continue;
            Goods *ptrG = nullptr;
            for (auto &goods : System::goods)
                if ((goods.val > 100 or tick <= 500) and goods.tag_select == false)
                    if (ptrG == nullptr or ptrG->dis[robot.x][robot.y] > goods.dis[robot.x][robot.y])
                        ptrG = &goods;
            ptrG->tag_select = true;
            robot.setTarget(*ptrG);
            robot.ptrgoods = ptrG;
        }
        return;
    }

    std::vector<Robot*> ptrRobot[c_berth_num];
    std::vector<Goods*> ptrGoods[c_berth_num], tmpSol;
    for (int i = 0; i < c_berth_num; ++ i)
    {
        for (auto &it : System::robot)
            if (it.ptrBerth == &System::berth[i])
                ptrRobot[i].push_back(&it);

        for (auto &it : System::goods)
            if (!it.tag_select and System::nearest[it.x][it.y] == i)
                ptrGoods[i].push_back(&it);
    }

    if (tick == 13387)
        tick = 13387;

    for (int i = 0; i < c_berth_num; ++ i)
        currentValue[i] = solve2_calcBerthValue(tick, System::berth[i], ptrRobot[i], ptrGoods[i], tmpSol);

    for (auto &robot : System::robot)
    {
        if (System::mapid == 1) break;
        double max_delta = 0;
        // Robot &robot = System::robot[tick % 10];
        std::vector<Robot*> Robot_from, Robot_to;
        if ((robot.ptrBerth != nullptr and !robot.ptrBerth->closed) and (robot.ptrgoods != nullptr or robot.goods)) continue;
        for (auto &berth : System::berth)
        {
            if (berth.closed) continue;
            if (robot.ptrBerth == &berth) continue;
            if (berth.dis[robot.x][robot.y] == INT_MAX) continue;

            std::vector<Robot*> tmpRobot_from, tmpRobot_to;
            for (auto &it : ptrRobot[robot.ptrBerth->id])
                if (it != &robot) tmpRobot_from.push_back(it);
            tmpRobot_to = ptrRobot[berth.id];
            tmpRobot_to.push_back(&robot);

            double tmpVal_from = solve2_calcBerthValue(tick, berth, tmpRobot_from, ptrGoods[robot.ptrBerth->id], tmpSol);
            double tmpVal_to = solve2_calcBerthValue(tick, berth, tmpRobot_to, ptrGoods[berth.id], tmpSol);

            if (robot.ptrBerth->closed) tmpVal_from = currentValue[robot.ptrBerth->id] = 0;
            double delta = tmpVal_from + tmpVal_to - (currentValue[robot.ptrBerth->id] + currentValue[berth.id]);
            if (tmpVal_to > 0 and currentValue[robot.ptrBerth->id] == 0 and delta == 0) delta = tmpVal_to;
            
            if (delta > max_delta and (System::nearby[robot.ptrBerth->id][berth.id] or robot.ptrBerth->closed or System::tick < 200))
            {
                max_delta = delta;
                trans_berth = &berth;

                Robot_from = tmpRobot_from;
                Robot_to = tmpRobot_to;
            }
        }
        if (max_delta > 0)
        {
            ptrRobot[robot.ptrBerth->id] = Robot_from;
            ptrRobot[trans_berth->id] = Robot_to;
            robot.ptrBerth = trans_berth;
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
            else /*test*/  if (ptrRobot[i][j]->ptrgoods == nullptr)
            {
                ptrRobot[i][j]->setTarget(*tmpSol[j]);
                ptrRobot[i][j]->ptrgoods = tmpSol[j];
                if (tmpSol[j] != nullptr)
                    tmpSol[j]->tag_select = true;
            }
    }
}

int berth_rank[10];// = {2,7,1,3,6,0,8,9,5,4};
void solve2_calcBoat(int tick)
{
    if (tick % 3000 == 0)// or System::mapid == 0)
    {
        for (int i = 0; i < 10; ++ i) berth_rank[i] = i;
        sort(berth_rank, berth_rank + 10, [](int arg1, int arg2)
            { return System::berth[arg1].goods.size() < System::berth[arg2].goods.size(); });
    }

    for (int i = 0; i < c_boat_num; ++ i)
    {
        // break;
        if (System::mapid == 1) break;

        int berth1 = i, berth2 = 9 - i;

        int left_time = (3000 - System::berth[berth_rank[berth1]].trans_time - System::berth[berth_rank[berth2]].trans_time - c_time_berth2b) / 2;
        int choice = System::berth[berth_rank[berth1]].trans_time > System::berth[berth_rank[berth2]].trans_time ? 0 : berth2 - berth1;
        if (System::boat[i].status != Boat::done) continue;
        if (System::boat[i].pos == -1)
        {
            System::boat[i].go(berth_rank[berth1 + choice]);
            continue;
        }
        int tmp = tick % 3000;
        if (tmp == 3000 - System::berth[berth_rank[berth2 - choice]].trans_time)
        {
            System::boat[i].go(-1);
            if (tick >= 3000 * 4) System::berth[berth_rank[berth2 - choice]].closed = System::mapchanged = true;
            continue;
        }
        if (tmp == System::berth[berth_rank[berth1 + choice]].trans_time + left_time)
        {
            System::boat[i].go(berth_rank[berth2 - choice]);
            if (tick >= 3000 * 4) System::berth[berth_rank[berth1 + choice]].closed = System::mapchanged = true;
            continue;   
        }
    }

    if (System::mapid == 0 and false)
    {
        for (int i = 0; i < c_boat_num; ++ i)
        {
            if (System::boat[i].status != Boat::done) continue;

            int tmp = tick % 2500;
            if (System::boat[i].pos == -1)
            {
                System::boat[i].go(berth_rank[i + 5]);
                continue;
            }
            if (System::berth[System::boat[i].pos].trans_time + tmp == 2500)
            {
                System::boat[i].go(-1);
                continue;
            }
        }
    }

    if (System::mapid == 1)
    {
        if (System::boat[4].status == Boat::done)
        {
            if (System::boat[4].pos == -1)
                System::boat[4].go(1);
            if (System::boat[4].goods == Boat::boat_capacity or tick == 15000 - System::berth[1].trans_time)
                System::boat[4].go(-1);
            if (tick == 11800) System::boat[4].go(-1);
        }
        if (System::boat[3].status == Boat::done)
        {
            if (System::boat[3].pos == -1)
                System::boat[3].go(2);
            if (System::boat[3].goods == Boat::boat_capacity or tick == 15000 - System::berth[2].trans_time)
                System::boat[3].go(-1);
            if (tick == 12000) System::boat[3].go(-1);
        }
        if (System::boat[2].status == Boat::done)
        {
            if (System::boat[2].pos == -1)
                System::boat[2].go(6);
            if (System::boat[2].goods == Boat::boat_capacity or tick == 15000 - System::berth[6].trans_time)
                System::boat[2].go(-1);
            if (tick == 11950) System::boat[2].go(-1);
        }
        if (System::boat[1].status == Boat::done)
        {
            if (System::boat[1].pos == -1)
                System::boat[1].go(8);
            if (System::boat[1].goods == Boat::boat_capacity or tick == 15000 - System::berth[8].trans_time)
                System::boat[1].go(-1);
            if (tick == 6000) System::boat[1].go(-1);
            if (tick == 11600) System::boat[1].go(-1);
        }
        if (System::boat[0].status == Boat::done)
        {
            if (System::boat[0].pos == -1)
                System::boat[0].go(9);
            if (System::boat[0].goods == Boat::boat_capacity or tick == 15000 - System::berth[9].trans_time)
                System::boat[0].go(-1);
            if (tick == 11800) System::boat[0].go(-1);
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
        for (int i = 0; i < 10; ++ i) berth_rank[i] = i;

        if (System::mapid == 1)
        {
            System::berth[0].closed = System::mapchanged = true;
            System::berth[3].closed = System::mapchanged = true;
            System::berth[4].closed = System::mapchanged = true;
            System::berth[5].closed = System::mapchanged = true;
            System::berth[7].closed = System::mapchanged = true;
        }
    }

    solve2_calcRobot(tick);
    solve2_calcBoat(tick);

    for (auto &it : System::robot)
        it.step(System::robot);
}