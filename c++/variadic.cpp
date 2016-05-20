#include <iostream>
#include <bitset>
#include <string>

template<typename T>
T sum(T v)
{
    return v;
}

template <typename T, typename... Args>
T sum(T first, Args... args)
{
    return first + sum(args...);
}


void print()
{
}

template <typename T, typename... Types>
void print(const T& first_arg, const Types&... args)
{
    std::cout << first_arg << std::endl;
    print(args...);
}


int main(int argc, char *argv[])
{
   print(7.5, "hallo", std::bitset<16>(377), 42);
   print("=================", sum(1, 2, 3, 4, 5, 6, 7, 8));
   print(sum(std::string("uno"), std::string(", "), std::string("dos")));

   return 0;
}


// Compiled with
// clang++ -fvisibility=hidden -s -fPIC -O3 -std=c++14 variadic.cpp -o variadic
