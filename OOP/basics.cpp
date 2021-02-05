#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
// #include<boost/bandwidth.hpp>

class Animal
{
private:
    std::string name;
    double height, weight;
    
    // static members are same for all objects of a class
    static int num_of_animals;

public:

    std::string get_name() { return this->name;}
    void set_name(std::string name) { this->name = name;}
    double get_height() { return this->height;}
    void set_height(double height) { this->height = height;}

    // function prototypes are also allowed
    double get_weight();
    void set_weight(double);
    void get_all_info();

    //static function to acces static members
    static int get_animal_num();

    // constructors
    Animal(std::string, double, double);
    Animal(); // default constructor

    // destructor
    ~Animal();
};

// function definitions
double Animal::get_weight() { return weight; }

void Animal::set_weight(double weight)
{
    this->weight = weight;
}

void Animal::get_all_info()
{
    std::cout << "Name - " << name <<
        "Height - " << height << 
        "Weight - " << weight  << '\n';
}

int Animal::num_of_animals = 0;

int Animal::get_animal_num() { return num_of_animals; }

Animal::Animal(std::string name, double height, double weight)
{
    this->name = name;
    this->height = height;
    this->weight = weight;
    num_of_animals++;
}

Animal::Animal()
{
    this->name = "NoName";
    this->height = 0;
    this->weight = 0;
    num_of_animals++;
}

Animal::~Animal()
{
    std::cout << "Animal " << name << " is destroyed!\n";
}

int main()
{
    Animal fred;
    fred.get_animal_num();
    fred.get_all_info();

    Animal tom("Tom", 33, 45);
    tom.get_all_info();

    tom.get_animal_num();
}
