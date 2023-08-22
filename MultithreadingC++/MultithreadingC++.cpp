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

    for (auto& set : datasets)
    {
        std::ranges::generate(set, rne);
    }

    NastihanTimer timer;
    for (auto& set : datasets)
    {
        for (auto x : set)
        {
            constexpr auto limit = (double)std::numeric_limits<int>::max();
            const auto y = (double)x / limit;
            set[0] += int(std::sin(std::cos(y)) * limit);
        }
    }
    auto t = timer.Peek();



    std::cout << "Processing took: " << t << " seconds\n";
    return 0;
}


