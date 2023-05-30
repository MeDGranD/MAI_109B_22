#include "../include/Vector.hpp"
#include <chrono>
#include <vector>

void benchmark()
{
    std::cout << "Initialization:" << std::endl;

    std::cout << "My vector:" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Vector<int> Vec1(1000000);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    std::vector<int> vec1(1000000);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;

    std::cout << "Push_back" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    Vector<int> Vec2;
    for (int64_t pushValue = 0; pushValue < 1000000; ++pushValue) {
        Vec2.push_back(pushValue);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    std::vector<int> vec2;
    for (int64_t pushValue = 0; pushValue < 1000000; ++pushValue) {
        vec2.push_back(pushValue);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;
    std::cout << "By-pass:" << std::endl;
    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t passCount = 0; passCount < 1000000; ++passCount) {
        int a = Vec2[passCount];
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t passCount = 0; passCount < 1000000; ++passCount) {
        int a = vec2[passCount];
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Pop_back:" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 1000000; ++popCount) {
        Vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (int64_t popCount = 0; popCount < 1000000; ++popCount) {
        vec2.pop_back();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Clear:" << std::endl;

    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    vec2.clear();
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    Vec2.clear();
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Reserve(10000):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (size_t reserveSize = 1; reserveSize < 10000; ++reserveSize) {
        Vec2.reserve(reserveSize);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (size_t reserveSize = 1; reserveSize < 10000; ++reserveSize) {
        vec2.reserve(reserveSize);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Reserve(100000):" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (size_t reserveSize = 1; reserveSize < 100000; ++reserveSize) {
        Vec2.reserve(reserveSize);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (size_t reserveSize = 1; reserveSize < 100000; ++reserveSize) {
        vec2.reserve(reserveSize);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Equalses:" << std::endl;
    Vector<int> Vec3(1000000);
    Vector<int> Vec4(1000000);
    std::vector<int> vec3(1000000);
    std::vector<int> vec4(1000000);

    std::cout << "operator==:" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    if (Vec3 == Vec4) {
        end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }

    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    if (vec3 == vec4) {
        end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;
    std::cout << "operator!=:" << std::endl;

    std::cout << "My vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    if (!(Vec3 != Vec4)) {
        end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }

    std::cout << "Library vector:" << std::endl;
    begin = std::chrono::steady_clock::now();
    if (!(vec3 != vec4)) {
        end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;
}
