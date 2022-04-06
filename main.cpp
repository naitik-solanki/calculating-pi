#include"arithmetic.hpp"
ll precision_in_base(ll precision, ll my_base) //Argument mai wrt base 10 hai
{
    return(ceil(precision * log2(10))/my_base);
}

// number convert_toDecimal(number n)
// {
//     number ans;
//     ans.digits.push_back(0);
//     ans.mini_power = 0;
//     ans.is_negative = false;
//     for(ll i=ans.digits.size() - 1;i<ans.digits.size();i++)
//     {
//         number a, b;
//         a.digits.push_back(ans.digits[i]);
//         a.is_negative = false;
//         a.mini_power = 0;

//         ans = add(multiply_Karatsuba(, 10), ans);
//     }
    
// }

int main()
{
    ll option, length, my_base;
    cout << "Option 1 Pi Digits \nOption 2 Root(2) \nPass the number of the decimal digits you want to print and the base at which you want to do the computations - ";
    cin >> option >> length >> my_base;
    ll base = 1;
    number ans;
    for(ll i=0;i< my_base;i++)
    {
        base *= 2;
    }
    ll prec_base = precision_in_base(length ,my_base);
    //cout << "prec_base - " << prec_base << endl;
    switch (option)
    {
    case(1):
        {
            ans = borwein(prec_base, base);
            //number ans = borwein(10);
            cout<<ans.mini_power<<" ";
            cout << "ans ";
            for(auto x: ans.digits)
            {
                cout << x << " ";
            }
            cout << endl;
            // print answer
            break;
        }
    case(2):
        {
            number a;
            a.digits.push_back(2);
            a.mini_power = 0;
            a.is_negative = false;
            ans = sq_root(a,prec_base, base);
            cout << "ans ";
            cout<<ans.mini_power<<" ";
            for(auto x: ans.digits)
            {
                cout << x << " ";
            }
            cout << endl;
            // print answer
            break;
        }
    
    default:
        break;
    }
    // number a,b;
    
    // a.digits.push_back(101);
    // a.digits.push_back(128);
    // b.digits.push_back(2);


    // // b.digits.push_back(25);
    // // b.digits.push_back(153);
    // // b.digits.push_back(153);
    // // b.digits.push_back(153);
    // // b.digits.push_back(25);
    // a.mini_power=-1;
    // b.mini_power=0;

    
    // // a.digits.clear();
    // // b.digits.clear();
    // // a.digits.push_back(4);
    // // a.digits.push_back(43);
    // // a.digits.push_back(154);
    // // a.digits.push_back(0);

    // // b.digits.push_back(140);
    // // b.digits.push_back(128);

    // // a.mini_power=0;
    // // b.mini_power=0;
    // // Normalize(a, b);
    // // long_Division(a, b);

    // // b.digits.clear();
    // // b.digits.push_back(128);

    // // // a.mini_power=0;
    // // // b.mini_power=0;
    // //Normalize(a,b);
    // number ans = borwein(10);
    // cout<<ans.mini_power<<" ";
    // cout << "ans ";
    // for(auto x: ans.digits)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
}
// 101 190 192 251 145 247
// 11 211 134 236 125 211