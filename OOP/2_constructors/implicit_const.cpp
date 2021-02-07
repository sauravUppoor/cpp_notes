// Without using default constructors - 3 constructors needed

#include <iostream>
#include <string>

class Ball {
private:
    std::string m_color{ "black" };
    double m_radius{ 10.0 };

public:
    Ball(std::string);
    Ball(double);
    Ball(std::string, double);
    Ball() {};
    void print();
};

Ball::Ball(std::string color)
{
    m_color = color;
}

Ball::Ball(double radius)
{
    m_radius = radius;
}

Ball::Ball(std::string color, double radius)
{
    m_color = color;
    m_radius = radius;
}

void Ball::print()
{
    std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
}

int main()
{
    Ball def{};
	def.print();
 
	Ball blue{ "blue" };
	blue.print();
	
	Ball twenty{ 20.0 };
	twenty.print();
	
	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();
 
	return 0;
}