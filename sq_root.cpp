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
        number prev = guess;
        guess = multiply_Karatsuba(half,add(temp,guess));
        number temp2= sub(guess,prev);
        if(temp2.mini_power + temp2.digits.size()<-2)
        {
            break;
        }

    }
    return guess;
}