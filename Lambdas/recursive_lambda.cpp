#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<numeric>
#include<sstream>
#include<ctime>
#include<functional>

std::vector<int> gen_rand_vector(int num, int min, int max);

int main()
{
    std::vector<int> vec_vals = gen_rand_vector(10, 1, 50);

    std::function<int(int)> Fib = [&](int n) {return n < 2 ? n : Fib(n-1) + Fib(n-2);};
    std::cout << Fib(6) << '\n'; // 8
    // 0 1 1 2 3 5 8

    // PROBLEM: use recursive lambdas to gen vector of n fibo numbers
    std::vector<int> fibs;
    int num;
    std::cout << "Enter n: ";
    std::cin >> num;

    for(int i = 0; i < num; ++i)
        fibs.push_back(Fib(i));

    for(auto val: fibs)
        std::cout << val << ' ';
    std::cout << '\n';

}

std::vector<int> gen_rand_vector(int num, int min, int max)
{
    srand(time(NULL));
    std::vector<int> rand_vec;
    int rand_val = 0;
    for(int i = 0; i < num; ++i)
    {
        rand_val = min + std::rand() %(max + 1 - min);
        rand_vec.push_back(rand_val);
    }
    return rand_vec;
}