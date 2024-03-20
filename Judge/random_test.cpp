#include <bits/stdc++.h>

// std::vector<int> data = {161, 24, 184, 137, 115, 182};
std::vector<int> data = {161, 143, 136, 50, 154, 181};


std::default_random_engine global_random_engine(1);
int random(int a, int b, std::default_random_engine &seed)
{
    std::uniform_int_distribution<int> d(a, b);
    return d(seed);
}

bool check(int seed)
{
    std::default_random_engine sd(seed);
    for (size_t i = 0; i < 21; ++ i)
        random(0, 1, sd);
    
    int count = 0, rand;
    bool f = false;
    for (size_t i = 0; i < 20; ++ i)
    {
        if (!f) rand = random(0, 199, sd);
            else f = false;
        for (size_t index = 0; index < data.size(); index += 2)
            if (rand == data[index])
            {
                ++ i;
                rand = random(0, 199, sd);
                if (rand == data[index + 1])
                    ++ count;
                else
                    f = true;
            }
    }
    return count >= data.size() / 2;
}

int main()
{

    // std::uniform_int_distribution<int> d(800, 1200);
    // std::default_random_engine s(3);
    // for (int i = 0; i < 21; ++ i)
    //     std::cout << d(s) << " ";
    // std::cout << "\n";

    for (size_t i = 1; i < INT_MAX; ++ i)
    {
        if (check(i))
        {
            std::cout << "\033[2K\r";
            std::cout << i << '\n';
            std::cout << 1000LL * i / INT_MAX / 10 << "." << 1000LL * i / INT_MAX % 10 << "%";
        }
        if (1000LL * i / INT_MAX > 1000LL * (i-1) / INT_MAX)
        {
            std::cout << "\033[2K\r";
            std::cout << 1000LL * i / INT_MAX / 10 << "." << 1000LL * i / INT_MAX % 10 << "%";
        }
    }
    system("pause");
    
    return 0;
}