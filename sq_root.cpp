#include"arithmetic.hpp"

number sq_root(number a,int prec_base,ll base)// standart implementation of newtons algorithm
{
    ll no_ofiterations = log2(prec_base) + 3;
    number half;
    half.mini_power=-1;
    half.digits.push_back(base/2);
    number guess;
    guess.mini_power=0;
    guess.is_negative=false;
    guess.digits.push_back(1);
    int i=0;
    number temp3 = a;
    while(i < 20)
    {
        number temp = long_Division(a,guess,prec_base, base);
        number prev = guess;
        number n = add(temp,guess, base);
        guess = mult(half,add(temp,guess, base), base);
        i++;
        a=temp3;
    }
    return guess;
}