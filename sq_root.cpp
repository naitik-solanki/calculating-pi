#include"arithmetic.hpp"
number sq_root(number a)
{
    number half;
    half.mini_power=-1;
    half.digits.push_back(base/2);
    number guess;
    guess = multiply_Karatsuba(half,a);
    while(1)
    {
        number temp = long_Division(a,guess);
        guess = multiply_Karatsuba(half,add(temp,guess));
        
    }
}