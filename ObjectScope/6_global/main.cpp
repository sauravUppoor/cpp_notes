// Global constants can be better defined (in pre C++17) using headers for definition
// and .cpp for declarations with extern const type since they will be 
// compiled only in this file.
// Best practice - use inline constexpr variables + define it in header file

#include "constant.h"
#include <iostream>

int main()
{
    int radius = 4;
    std::cout << "Area = " << 2 * constant::pi * radius;
}