#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cmath>
#include <limits>
#include "NastihanTimer.h"


constexpr size_t DATASET_SIZE = 5000000;

int main()
{
    std::minstd_rand rne;
    std::vector<std::array<int, DATASET_SIZE>> datasets{ 4 };

    NastihanTimer timer;
    for (auto& set : datasets)
    {
        std::ranges::generate(set, rne);
    }
    auto t = timer.Peek();



    std::cout << "Generation took: " << t << " seconds\n";
    return 0;
}


