#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cmath>
#include <limits>
#include <thread>
#include "NastihanTimer.h"


constexpr size_t DATASET_SIZE = 5000000;

void Process(std::array<int, DATASET_SIZE>& set, int &sum, std::mutex& mtx)
{
    for (auto x : set)
    {
        mtx.lock();
        constexpr auto limit = (double)std::numeric_limits<int>::max();
        const auto y = (double)x / limit;
        sum += int(std::sin(std::cos(y)) * limit);
        mtx.unlock();

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
    
    int sum = 0;
    std::mutex mtx;

    NastihanTimer timer;
    for (auto& set : datasets)
    {
        workers.push_back(std::thread(Process, std::ref(set), std::ref(sum), std::ref(mtx)));
    }
    for (auto& w : workers)
    {
        w.join();
    }
    auto t = timer.Peek();



    std::cout << "Processing took: " << t << " seconds\n";
    std::cout << "The accumulated result is: " << sum << "\n";
    return 0;
}


