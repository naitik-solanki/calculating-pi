#include"arithmetic.hpp"
int main()
{
    number a,b;
    a.digits.push_back(1);
    a.digits.push_back(1);

    b.digits.push_back(92);

    a.mini_power=0;
    b.mini_power=0;
    
    number ans3 = multiply_Karatsuba(a, b);
    for(auto x:ans3.digits)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
// 101 190 192 251 145 247
// 11 211 134 236 125 211