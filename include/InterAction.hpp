#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class InterAction
{
public:

    static void Init();
    static void TickInput();

    static void clearCommand();
    static void printCommand();

    static void lbot(int x, int y);
    static void move(size_t id, int arg);
    static void get(size_t id);
    static void pull(size_t id);

    static void lboat(int x, int y);
    static void dept(size_t id);
    static void berth(size_t id);
    static void rot(size_t id, int arg);
    static void ship(size_t id);
};

#endif