#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cmath>
#include <limits>
#include <thread>
#include "NastihanTimer.h"


constexpr size_t DATASET_SIZE = 5000000;

void Process(std::array<int, DATASET_SIZE>& set)
{
    for (auto x : set)
    {
        constexpr auto limit = (double)std::numeric_limits<int>::max();
        const auto y = (double)x / limit;
        set[0] += int(std::sin(std::cos(y)) * limit);
    }
}

int main()
{
    std::minstd_rand rne;
    std::vector<std::array<int, DATASET_SIZE>> datasets{ 4 };
    std::vector<std::thread> workers;

    for (auto& set : datasets)
    {
        std::ranges::generate(set, rne);
    }

    NastihanTimer timer;
    for (auto& set : datasets)
    {
        workers.push_back(std::thread(Process, std::ref(set)));
    }
    for (auto& w : workers)
    {
        w.join();
    }
    auto t = timer.Peek();



    std::cout << "Processing took: " << t << " seconds\n";
    return 0;
}


