#include <iostream>

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 15001; i++)
    {
        std::cout << "OK\n";
        fflush(stdout);
    }
    
    return 0;
}
