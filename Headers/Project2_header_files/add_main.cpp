// Header files order (alphabetically each category) -
// 1. User defined
// 2. 3rd party
// 3. Standard Library

#include "add.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
    std::cout << "Sum of 3, 4 = " << add(3,4) << '\n';
    // return 0;
}