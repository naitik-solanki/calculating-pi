#include"arithmetic.hpp"
number sq_root(number a)
{
    cout << "a ";
    for(auto x: a.digits)
    {
        cout << x << " ";
    }
    cout << endl;
    number half;
    half.mini_power=-1;
    half.digits.push_back(base/2);
    number guess;
    guess.mini_power=0;
    guess.is_negative=false;
    guess.digits.push_back(1);
    while(1)
    {
        number temp = long_Division(a,guess,9);
        number prev = guess;
        guess = multiply_Karatsuba(half,add(temp,guess));
        number temp2= sub(guess,prev);
        if((temp2.mini_power + temp2.digits.size())<-5)
        {
            break;
        }
        cout<<"ha ha ha"<<endl;
    }
    return guess;
}