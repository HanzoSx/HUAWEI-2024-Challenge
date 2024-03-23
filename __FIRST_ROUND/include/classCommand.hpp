#ifndef CLASS_COMMAND_H
#define CLASS_COMMAND_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Command
{
public:

    static void print()
    {
        for (auto& it : RobotCmd) cout << it << "\n";
        for (auto& it : BoatCmd) cout << it << "\n";
        
        cout << "OK\n";
        fflush(stdout);
    }

    static void clear()
    {
        RobotCmd.clear();
        BoatCmd.clear();
    }

    static void move(size_t id, int direcet)  { RobotCmd.emplace_back("move " + to_string(id) + " " + to_string(direcet)); }
    static void get(size_t id)                { RobotCmd.emplace_back("get " + to_string(id)); }
    static void pull(size_t id)               { RobotCmd.emplace_back("pull " + to_string(id)); }

    static void ship(size_t id, int berth_id) { BoatCmd.emplace_back("ship " + to_string(id) + " " + to_string(berth_id)); }
    static void go(size_t id)                 { BoatCmd.emplace_back("go " + to_string(id)); }

private:

    static vector<string> RobotCmd, BoatCmd;

};


#endif