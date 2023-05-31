#include <deque>
#include <chrono>
#include <algorithm>
#include "../include/Deque.hpp"

void benchmark(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cout << "Initialization(big size):" << std::endl;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::deque<int> stdDQ(1000000);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    deque<int> myDQ(1000000);
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Clear(resize 0):" << std::endl;

    begin = std::chrono::steady_clock::now();
    stdDQ.resize(0);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    myDQ.resize(0);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Push_back:" << std::endl;

    std::deque<int> stdDQ2;
    deque<int> myDQ2;

    begin = std::chrono::steady_clock::now();
    for(size_t value = 0; value < 1000000; ++value){
        stdDQ2.push_back(value);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t value = 0; value < 1000000; ++value){
        myDQ2.push_back(value);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Push_front:" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t value = 0; value < 1000000; ++value){
        stdDQ2.push_front(value);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t value = 0; value < 1000000; ++value){
        myDQ2.push_front(value);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Pop_back:" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t value = 0; value < 1000000; ++value){
        stdDQ2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t value = 0; value < 1000000; ++value){
        myDQ2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    std::cout << "Pop_front:" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t value = 0; value < 1000000; ++value){
        stdDQ2.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t value = 0; value < 1000000; ++value){
        myDQ2.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    //with deque(): resize = 1000000; start = 1000001; speed X2 in compare with std::deque!

    std::cout << std::endl;
    std::cout << "sort:" << std::endl;

    for(size_t value = 0; value < 10000; ++value){
        stdDQ2.push_back((value%2 - value%3) + value /156 - value%42);
    }
    begin = std::chrono::steady_clock::now();
    std::sort(stdDQ2.begin(), stdDQ2.end());
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    for(size_t value = 0; value < 10000; ++value){
        myDQ2.push_back((value%2 - value%3) + value /156 - value%42);
    }
    begin = std::chrono::steady_clock::now();
    myDQ2.sort();
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

}