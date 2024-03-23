#include <math.h>

#include "classCommand.hpp"
#include "classSystem.hpp"
#include <bits/stdc++.h>
const int c_berth_dis_range = 20;


void solve1_CalcBerthFactor()
{
    for (auto &it : System::berth)
    {
        it.factor = 0;
        for (auto &target : System::goods)
            if (it.dis[target.x][target.y] <= c_berth_dis_range)
                it.factor ++;
    }
}

void solve1_CalcGoodsFactor(int tick)
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


double solve1_function(int disRG, int hp, int val, int disGB, int ber_val)
{
    {
        if (hp + 10 < disRG) return -INT_MAX;
        if (val < 150) return -INT_MAX;
        int dis = disRG + disGB;
        
        return exp(-0.00388*hp) * (double)val / (double)dis;
    }
    {
        // double e[5] = {-1, -1, 1, -1, 1};
        // return e[0] * disRG + e[1] * hp + e[2] * val + e[3] * disGB + e[4] * ber_val;
        double e[3] = {10, 780, 1};
        return e[0] * val / (disRG + disGB) + e[1] / hp + e[2] * ber_val;
    }
}

void solve1_CalcRobotTarget()
{
    for (auto &it : System::robot)
    {
        if (it.map != nullptr and it.map->dis[it.x][it.y] == 0)
        {
            if (it.goods == 0 and it.ptrgoods != nullptr) it.get();
                else if (it.goods) it.pull();
        }
        if (!it.goods)
        {
            Goods *tmp = nullptr;
            double tmp_func = 0;
            for (auto &target : System::goods)
            {
                if (target.tag_select and &target != it.ptrgoods) continue;
                double now = solve1_function(target.dis[it.x][it.y], target.factor.hp, target.factor.val, target.factor.dis, target.factor.ber_val);
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

void solve1_DoBoat(int tick)
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
        if (tmp == System::berth[i * 2 + choice].trans_time + left_time)
        {
            System::boat[i].go(i * 2 +  1 - choice);
            continue; 
        }
        if (tmp == 3000 - System::berth[i * 2 + 1 - choice].trans_time)
        {
            System::boat[i].go(-1);
            continue; 
        }

    }
}


int berth_rank2[10];// = {2,7,1,3,6,0,8,9,5,4};

void solve1_calcBoat(int tick)
{
    if (tick % 3000 == 0)// or System::mapid == 0)
    {
        for (int i = 0; i < 10; ++ i) berth_rank2[i] = i;
        sort(berth_rank2, berth_rank2 + 10, [](int arg1, int arg2)
            { return System::berth[arg1].goods.size() < System::berth[arg2].goods.size(); });
    }

    for (int i = 0; i < c_boat_num; ++ i)
    {
        // break;

        int berth1 = i, berth2 = 9 - i;

        int left_time = (3000 - System::berth[berth_rank2[berth1]].trans_time - System::berth[berth_rank2[berth2]].trans_time - c_time_berth2b) / 2;
        int choice = System::berth[berth_rank2[berth1]].trans_time > System::berth[berth_rank2[berth2]].trans_time ? 0 : berth2 - berth1;
        if (System::boat[i].status != Boat::done) continue;
        if (System::boat[i].pos == -1)
        {
            System::boat[i].go(berth_rank2[berth1 + choice]);
            continue;
        }
        int tmp = tick % 3000;
        if (tmp == 3000 - System::berth[berth_rank2[berth2 - choice]].trans_time)
        {
            System::boat[i].go(-1);
            if (tick >= 3000 * 4) System::berth[berth_rank2[berth2 - choice]].closed = System::mapchanged = true;
            continue;
        }
        if (tmp == System::berth[berth_rank2[berth1 + choice]].trans_time + left_time)
        {
            System::boat[i].go(berth_rank2[berth2 - choice]);
            if (tick >= 3000 * 4) System::berth[berth_rank2[berth1 + choice]].closed = System::mapchanged = true;
            continue;   
        }
    }
}
void solve1(int tick)
{

    for (auto &it : System::robot)
        it.step(System::robot);
    if (tick == 1) for (int i = 0; i < 10; ++ i) berth_rank2[i] = i;
    solve1_CalcBerthFactor();
    solve1_CalcGoodsFactor(tick);
    solve1_CalcRobotTarget();
    // solve1_DoBoat(tick);
    solve1_calcBoat(tick);

}