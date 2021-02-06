// Linkage property of identifiers and not variables
// Internal Linkage - identifier accessible in same file but not other files

// const and constexpr --> default internal linkage
// global variables + static --> internal linkage

#include <iostream>

static int g_x {10};
const int g_y { 1 };
constexpr int g_z { 2 };

int add(int, int);

int main() {
    std::cout << add(3,4) << '\n'; // access add funtion of this file and not of a.cpp
    std::cout << g_x << ' ' << g_y << ' ' << g_z << ' ' << '\n';
}

int add(int x, int y) {
    return x * y;
}