#include"arithmetic.hpp"
ll precision_in_base(ll precision, ll my_base) //Argument mai wrt base 10 hai
{
    return(ceil(precision * log2(10))/my_base);
}

int main()
{
    number n;
    n.digits.push_back(3);
    n.digits.push_back(36);
    n.digits.push_back(62);
    n.mini_power = -2;
    n.is_negative = false;
    cout << convert_toDecimal(n, 10, 256) << endl;
    // ll option, length, my_base;
    // cout << "Option 1 Pi Digits \nOption 2 Root(2) \nPass the number of the decimal digits you want to print and the base at which you want to do the computations - ";
    // cin >> option >> length >> my_base;
    // ll base = 1;
    // number ans;
    // for(ll i=0;i< my_base;i++)
    // {
    //     base *= 2;
    // }
    // ll prec_base = precision_in_base(length ,10);
    // //cout << "prec_base - " << prec_base << endl;
    // switch (option)
    // {
    // case(1):
    //     {
    //         ans = borwein(length, 10);
    //         //number ans = borwein(10);
    //         cout<<ans.mini_power<<" ";
    //         cout << "ans ";
    //         for(auto x: ans.digits)
    //         {
    //             cout << x << " ";
    //         }
    //         cout << endl;
    //         // print answer
    //         break;
    //     }
    // case(2):
    //     {
    //         number a;
    //         a.digits.push_back(2);
    //         a.mini_power = 0;
    //         a.is_negative = false;
    //         ans = sq_root(a,prec_base, base);
    //         cout << "ans ";
    //         cout<<ans.mini_power<<" ";
    //         for(auto x: ans.digits)
    //         {
    //             cout << x << " ";
    //         }
    //         cout << endl;
    //         // print answer
    //         break;
    //     }
    
    // default:
    //     break;
    // }
    // number a,b;
    
    // a.digits.push_back(9);
    // a.digits.push_back(9);
    // b.digits.push_back(9);
    // b.digits.push_back(9);

    // a.mini_power=0;
    // b.mini_power=0;
    // number ans = mult(a, b, 10);
    // cout<<ans.mini_power<<" ";
    // cout << "ans ";
    // for(auto x: ans.digits)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
}
