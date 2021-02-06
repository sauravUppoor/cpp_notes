// Types of initialisations -
// 1. Static - constexpr variables are initialised first
// 2. Dynamic - non-constexpre variables are initialised
// Best practice - avoid dynamic initialisations of variables. Why? Read below.

#include <iostream>

// forward declarations
int initx(); 
int inity();

int g_x{ initx() }; //g_x initialised first
int g_y{ inity() };

int initx()
{
    return g_y; // g_y is not initialised yet
}

int inity()
{
    return 5;
}

int main() 
{
    std::cout << g_x << ' ' << g_y << '\n'; // 0 5 and not 5 5
}