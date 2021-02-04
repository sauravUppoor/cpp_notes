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

    // Store sum of corresponding elements of 2 vectors in third
    std::vector<int> vec1 = {1,2,3,4,5};
    std::vector<int> vec2 = {1,2,3,4,5};
    std::vector<int> vec3(5);

    // transform applies function on elements and returns value to an element
    // v1 [1,2,3,4,5]
    // v2 [1,2,3,4,5,6,7]
    // transform(v1,v2,v3)
    // -> v3 [f1,f2,f3,f4,f5]
    transform(vec1.begin(), vec1.end(),
                    vec2.begin(), vec3.begin(),
                    [&](int x, int y) {return x+y;});

    for(auto val: vec3)
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