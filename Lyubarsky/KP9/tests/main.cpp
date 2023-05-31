#include "../include/Table.hpp"
#include <vector>
#include <chrono>
#include <algorithm>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Table<int> table1;
    std::vector<std::pair<double, int>> table2;

    for(size_t i = 0; i < 100000; ++i){
        table1.push_back(std::pair<double, int>(((i*13)/7)%15, 1));
        table2.push_back(std::pair<double, int>(((i*13)/7)%15, 1));
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    table1.sort();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    std::sort(table2.begin(), table2.end(), [](std::pair<double, int> a, std::pair<double, int> b) { return a.first < b.first; });
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;


    return 0;
}