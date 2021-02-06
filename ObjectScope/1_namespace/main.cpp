// .h files --> header guards
// .cpp files --> namespaces
// namespace should generally start with lowercase
// nested namespaces should be avoided
// Applications - When you write a library or code 
//     that you want to distribute to others, always 
//     place your code inside a namespace. The code your 
//     library is used in may not follow best practices -- 
//     in such a case, if your library’s declarations aren’t 
//     in a namespace, there’s an elevated chance for naming 
//     conflicts to occur. As an additional advantage, placing 
//     library code inside a namespace also allows the 
//     user to see the contents of your library by using their 
//     editor’s auto-complete and suggestion feature.

#include "circle.h"
#include "growth.h"
#include <iostream>

int doSomething(int x, int y) {
    return x * y;
}

namespace foo {
    int doSomething(int x, int y) {
        return x - y;
    }
}

namespace goo {
    int doSomething(int x, int y) {
        return x + y;
    }
}

int main() {
    std::cout << foo::doSomething(4,3) << '\n';
    std::cout << goo::doSomething(4,3) << '\n';
    std::cout << ::doSomething(4,3) << '\n'; // global namespace

    // namespace in different headers
    std::cout << basicMath::e << '\n';
    std::cout << basicMath::pi << '\n';
}