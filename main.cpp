#include <vector>
#include <queue>

#include <iostream>
#include <fstream>

#include "classCommand.hpp"
#include "classSystem.hpp"

// #include "sdk.hpp"



void solve(int tick)
{
    if (tick == 1)
    {
        for (size_t i = 0; i < c_boat_num; ++ i)
            Command::ship(i, i);
        for (size_t i = 0; i < c_robot_num; ++ i)
            System::robot[i].setTarget(System::berth[i]);
    }

    for (auto &it : System::robot)
        it.step(System::robot);


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
    // std::ifstream file("input.txt");
    // std::cin.rdbuf(file.rdbuf());


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
