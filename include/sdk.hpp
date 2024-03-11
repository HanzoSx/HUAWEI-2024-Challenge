#include <bits/stdc++.h>
using namespace std;

const int n = 200;
const int robot_num = 10;
const int berth_num = 10;
const int sdk_N = 210;

struct sdk_Robot
{
    int x, y, goods;
    int status;
    int mbx, mby;
    sdk_Robot() {}
    sdk_Robot(int startX, int startY) {
        x = startX;
        y = startY;
    }
}sdk_robot[robot_num + 10];

struct sdk_Berth
{
    int x;
    int y;
    int transport_time;
    int loading_speed;
    sdk_Berth(){}
    sdk_Berth(int x, int y, int transport_time, int loading_speed) {
        this -> x = x;
        this -> y = y;
        this -> transport_time = transport_time;
        this -> loading_speed = loading_speed;
    }
}sdk_berth[berth_num + 10];

struct sdk_Boat
{
    int num, pos, status;
}sdk_boat[10];

int sdk_money, boat_capacity, id;
char sdk_ch[sdk_N][sdk_N];

void sdk_Init()
{
    for(int i = 1; i <= n; i ++)
        scanf("%s", sdk_ch[i] + 1);
    for(int i = 0; i < berth_num; i ++)
    {
        int id;
        scanf("%d", &id);
        scanf("%d%d%d%d", &sdk_berth[id].x, &sdk_berth[id].y, &sdk_berth[id].transport_time, &sdk_berth[id].loading_speed);
    }
    scanf("%d", &boat_capacity);
    char okk[100];
    scanf("%s", okk);
    printf("OK\n");
    fflush(stdout);
}

int sdk_Input()
{
    scanf("%d%d", &id, &sdk_money);
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i ++)
    {
        int x, y, val;
        scanf("%d%d%d", &x, &y, &val);
    }
    for(int i = 0; i < robot_num; i ++)
    {
        int sts;
        scanf("%d%d%d%d", &sdk_robot[i].goods, &sdk_robot[i].x, &sdk_robot[i].y, &sts);
    }
    for(int i = 0; i < 5; i ++)
        scanf("%d%d\n", &sdk_boat[i].status, &sdk_boat[i].pos);
    char okk[100];
    scanf("%s", okk);
    return id;
}