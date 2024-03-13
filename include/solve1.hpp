#include <math.h>

#include "classCommand.hpp"
#include "classSystem.hpp"

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
        if (val < 100) return -INT_MAX;
        int dis = disRG + disGB;
        // return -dis;
        return val / dis;
        return exp(-0.002*hp) * 2 + val / dis;
    }
    {
        double e[5] = {-1, -1, 1, -1, 1};
        return e[0] * disRG + e[1] * hp + e[2] * val + e[3] * disGB + e[4] * ber_val;
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

void solve1(int tick)
{

    for (auto &it : System::robot)
        it.step(System::robot);

    solve1_CalcBerthFactor();
    solve1_CalcGoodsFactor(tick);
    solve1_CalcRobotTarget();
    solve1_DoBoat(tick);

}