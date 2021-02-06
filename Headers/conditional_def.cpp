#include<iostream>
#define FRED // Without substituition
// #define BOB 
#define Name "Saurav" // Object-like MACRO with substitution

void Foo()
{
#define Game "Chess" // This will get defined since it is evaluated during compile time
                     //  line by line
}

int main()
{
#ifdef FRED
    std::cout << "Fred\n";
#endif

#ifndef BOB
    std::cout << "Bob\n";
#endif

    std::cout << "User name - " << Name << '\n';

#ifdef Game
    std::cout << "Plays - " << Game << '\n';
#endif

#if 0 // Dont compile anything in this block
    std::cout << "This will not be printed :(";
#endif
    return 0;
}