#include <iostream>
#include <vector>
#include <array>
#include <random>

constexpr size_t DATASET_SIZE = 5000000;

int main()
{
    std::minstd_rand rne;
    std::vector<std::array<int, DATASET_SIZE>> datasets{ 4 };

    for (auto& arr : datasets)
    {
        std::ranges::generate(arr, rne);
    }

    std::cout << "Hello World!\n";
    return 0;
}


