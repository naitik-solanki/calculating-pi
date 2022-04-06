#include"arithmetic.hpp"

// double base2m_to_decimal(number n)
// {
//     int len = n.digits.size() - n.mini_power;
//     int power = 1;
//     int num = 0;  
//     int i;

//     for (i = len - 1; i >= 0; i--)
//     {
//         if (val(str[i]) >= base)
//         {
//             printf("Invalid Number");
//             return -1;
//         }
//         num += val(str[i]) * power;
//         power = power * base;
//     }
//     return num;
// }

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
    while(i<20)
    {
        //cout<<"ha ha ha"<<endl;
        //cout << "prec - " << precision << endl;
        number temp = long_Division(a,guess,precision);
        //cout<<"yaa"<<endl;
        number prev = guess;
        // cout << "temp = ";
        // cout<<temp.mini_power<<" ";
        // for(auto x: temp.digits)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        number n = add(temp,guess);
        // cout << "add = ";
        // cout<<n.mini_power<<" ";
        // for(auto x: n.digits)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        guess = multiply_Karatsuba(half,add(temp,guess));
        //number temp2= sub(guess,prev);
        i++;
        a=temp3;
       //cout << "a mini power = ";
        // cout<<a.mini_power<<" ";
        // for(auto x: a.digits)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // cout << "guess mini power = ";
        // cout<<guess.mini_power<<" ";
        // for(auto x: guess.digits)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
    }
    return guess;
}