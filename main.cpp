#include"arithmetic.hpp"
int main()
{
    number a,b;
    a.digits.push_back(1);
    a.digits.push_back(1);
    a.is_negative=false;

    b.digits.push_back(9);
    b.digits.push_back(2);
    b.is_negative=false;

    a.mini_power=0;
    b.mini_power=0;
    
    number ans3 = sub(a, b);
    cout<<ans3.is_negative<<endl;
    for(auto x:ans3.digits)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
// 101 190 192 251 145 247
// 11 211 134 236 125 211