#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<numeric>
#include<sstream>
#include<ctime>

std::vector<int> gen_rand_vector(int num, int min, int max);

int main()
{
    std::vector<int> vec_vals = gen_rand_vector(10, 1, 50);

    // for each lambda
    int sum = 0;
    std::for_each(vec_vals.begin(), vec_vals.end(),
                    [&](int x) {sum += x;});
    std::cout << sum << '\n';

    // PROBLEM: create a dynamic array in which each element is divisible by 
    // a divisor entered by user.

    int divisor;
    std::cout << "Enter divisor: ";
    std::cin >> divisor;

    std::vector<int> div_vec;
    std::copy_if(vec_vals.begin(), vec_vals.end(),
                    std::back_inserter(div_vec),
                    [divisor](int x) {return x%divisor == 0;});
    
    for(auto val: div_vec)
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