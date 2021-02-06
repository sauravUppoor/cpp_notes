// nested namespaces should be avoided

#include <iostream>

namespace foo {
    int sub(int x, int y) {
        return x - y;
    }

    namespace goo {
        int add(int x, int y) {
            return x + y;
        }
    }
}

// C++17 version
namespace foo::goo {
    int print() {
        return 4;
    }
}

int main() {
    std::cout << foo::goo::add(3,4) << '\n';
    
    namespace boo = foo::goo;

    std::cout << boo::print() << '\n';
    std::cout << foo::sub(4,3) << '\n';

}