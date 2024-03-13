#include "classCommand.hpp"
#include "classSystem.hpp"

// #include "sdk.hpp"

#include "solve1.hpp"



int main()
{

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
        solve1(System::tick);
        Command::print();

        System::Update_back();
    }

    System::log("IMP ", "Robot Pull = " + std::to_string(System::pull_sum));
    System::log("IMP ", "Robot Pull Value = " + std::to_string(System::pull_value_sum));
    System::log("IMP ", "Boat Trans = " + std::to_string(System::boat_trans_goods));
    System::log("IMP ", "Boat Trans Value = " + std::to_string(System::boat_trans_val));
    System::log("IMP ", "Goods Sum = " + std::to_string(System::goods_sum));
    System::log("IMP ", "Goods Val = " + std::to_string(System::goods_val));

    return 0;
}
