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

    // Sort lambda
    std::sort(vec_vals.begin(), vec_vals.end(),
                [](int a, int b) {return a > b;});
    
    for(auto val: vec_vals)
        std::cout << val << ' ';
    std::cout << '\n';

    // Copy if Lambda
    std::vector<int> even_vals;
    std::copy_if(vec_vals.begin(), vec_vals.end(),
                    std::back_inserter(even_vals),
                    [](int a) {return a%2 == 0;});

    for(auto val: even_vals)
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