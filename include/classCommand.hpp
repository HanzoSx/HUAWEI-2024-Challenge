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

    static void lbot(int x, int y)            { RobotCmd.emplace_back("lbot " + to_string(x) + " " + to_string(y)); }
    static void move(size_t id, int direcet)  { RobotCmd.emplace_back("move " + to_string(id) + " " + to_string(direcet)); }
    static void get(size_t id)                { RobotCmd.emplace_back("get " + to_string(id)); }
    static void pull(size_t id)               { RobotCmd.emplace_back("pull " + to_string(id)); }

    static void lboat(int x, int y)           { RobotCmd.emplace_back("lboat " + to_string(x) + " " + to_string(y)); }
    static void dept(size_t id)               { RobotCmd.emplace_back("dept " + to_string(id)); }
    static void berth(size_t id)              { RobotCmd.emplace_back("berth " + to_string(id)); }
    static void rot(size_t id, int direcet)   { RobotCmd.emplace_back("rot " + to_string(id) + " " + to_string(direcet)); }
    static void ship(size_t id)               { RobotCmd.emplace_back("ship " + to_string(id)); }

private:

    static vector<string> RobotCmd, BoatCmd;

};


#endif