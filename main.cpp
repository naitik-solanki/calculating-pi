#include"arithmetic.hpp"
int main()
{
    number a,b;
    a.digits.push_back(2);
    a.digits.push_back(3);
    a.digits.push_back(4);

    b.digits.push_back(2);
    b.digits.push_back(1);

    a.mini_power=-1;
    b.mini_power=-1;

    number ans = add(a,b);
    number ans2 = sub(a,b);
    for(auto x:ans2.digits)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
//        101 190 192 251 145 247
// 11 211 134 236 125 211