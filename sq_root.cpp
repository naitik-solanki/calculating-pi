#include"arithmetic.hpp"
number sq_root(number a,int precision)
{
    number half;
    half.mini_power=-1;
    half.digits.push_back(base/2);
    number guess;
    guess.mini_power=0;
    guess.is_negative=false;
    guess.digits.push_back(1);
    int i=0;
    number temp3 = a;
    while(i<14)
    {
        //cout<<"ha ha ha"<<endl;
        number temp = long_Division(a,guess,precision);
        cout<<"yaa"<<endl;
        number prev = guess;
        guess = multiply_Karatsuba(half,add(temp,guess));
        cout<<"ye to chalega hi"<<endl;
        number temp2= sub(guess,prev);
        cout<<"ye kaise nhi chalega bhai"<<endl;
        i++;
        a=temp3;
       cout << "a mini power = ";
        cout<<a.mini_power<<" ";
        for(auto x: a.digits)
        {
            cout << x << " ";
        }
        cout << endl;
        cout << "guess mini power = ";
        cout<<guess.mini_power<<" ";
        for(auto x: guess.digits)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return guess;
}