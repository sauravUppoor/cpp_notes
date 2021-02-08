// Templates --> same definition for different data types and 
//      return values

#include <iostream>

// we can also pass class objects in template
class Cents {
private:
    int m_cents;
public:
    Cents(int cents) {
        m_cents = cents;
    }

    // operator overloading for using in templates.
    // each class can have its own overloaded operators
    void print() {
        std::cout << m_cents << '\n';
    }

    friend bool operator>(const Cents& c1, const Cents& c2) {
        return (c1.m_cents > c2.m_cents);
    }

    friend std::ostream& operator<<(std::ostream& out, const Cents &cent) {
        out << cent.m_cents << " cents!";
        return out;
    }

    // Cents return type are not friend functions
    Cents& operator+=(const Cents &cent) {
        m_cents += cent.m_cents;
        return *this;
    }

    Cents& operator/=(int value) {
        m_cents /= value;
        return *this;
    }
};

// function template

// Template 1 - Add
template <typename T> // template parameter defintion
const T add(const T& x, const T& y)
{
    return x + y;
}

// Template 2 - Max
template <typename T>
const T& comp(const T& x, const T& y) {
    return (x > y) ? x : y;
}

// Template 3 - average
template<typename T>
T average(T *array, int N) {
    T sum(0);
    for(int i{ 0 }; i < N; ++i)
        sum += array[i];
    sum /= N;
    return sum;
}

int main()
{
    std::cout << add(3,4) << '\n';
    std::cout << add(3.44, 5.66) << '\n';
    std::cout << add('a', '6') << '\n';

    // passing class objects and ibuilt data types
    std::cout << comp(3, 4) << '\n';
    std::cout << comp(3.44, 5.66) << '\n';
    std::cout << comp('a', '6') << '\n';
    Cents A{ 3 };
    Cents B{ 4 };
    Cents C{ comp(A,B) };
    C.print();

    // using average template
    int arr[]{ 3,4,5,6 };
    std::cout << "Average of int array = " << average(arr, 4) << '\n';

    double arr2[]{ 3.33, 4.44, 5.55 };
    std::cout << "Average of double array = " << average(arr2, 3) << '\n';

    Cents arr3[]{ Cents(5), Cents(4), Cents(3) };
    std::cout << "Average of cents array = " << average(arr3, 3) << '\n';
}