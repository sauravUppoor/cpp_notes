/* In object-oriented programming, Encapsulation 
    (also called information hiding) is the process of keeping the 
    details about how an object is implemented hidden away from users 
    of the object. Instead, users of the object access the object through 
    a public interface.

Benefits - 
* encapsulated classes are easier to use and reduce the complexity of your programs
* encapsulated classes help protect your data and prevent misuse
* encapsulated classes are easier to change
* encapsulated classes are easier to debug

Access functions - functions used to access private members, use minimally.

Constructor - initialise member  functions
*/

#include <iostream>
#include <string>

class Ball {
private:
    std::string m_color;
    double m_radius;

public:
    // using default constructor
    Ball()
    {
        m_color = "black";
        m_radius = 10.0;
    }

    // default arguments
    // covers Ball(string, double), Ball(string), Ball();
    Ball(std::string color, double radius=10.0);
    //covers Ball(double);
    Ball(double radius);

    void print();
};

Ball::Ball(std::string color, double radius)
{
    m_color = color;
    m_radius = radius;
}

Ball::Ball(double radius)
{
    // here m_color is not defined.
    m_radius = radius;
}

void Ball::print()
{
    std::cout << m_color << ' ' << m_radius << '\n';
}

int main()
{
    Ball b1{"red"};
    Ball b2{20.9};
    Ball b3{};
    Ball b4("blue", 3.3);

    b1.print();
    b2.print();
    b3.print();
    b4.print();

    // Use default initialisations in private members
}

