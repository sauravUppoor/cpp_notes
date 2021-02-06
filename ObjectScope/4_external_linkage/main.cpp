// External Linkage - identifiers accesssible outside of files
// global variables --> external linked
// const & constexpr + extern --> external linked
// forward declarations --> use extern keyword

#include <iostream>

extern int g_x;
extern const int g_y;
// extern constexpr int g_z; constexpre cant be forward declared! No use of forward declaring

int main() {
    std::cout << g_x << ' ' << g_y << "\n";
}
