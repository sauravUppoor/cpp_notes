// Inline variables - multiple definitions allowed
// Restrictions -
// 1. Definitions must be identical
// 2. Defintions must be present in any file using the variable

#include "constant.h"
#include <iostream>

int main()
{
    int radius = 4;
    std::cout << "Area - " << 2 * constant::pi * radius;
}