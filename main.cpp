#include"arithmetic.hpp"
int main()
{
    number a,b;
    a.digits.push_back(13);
    a.digits.push_back(0);
    b.digits.push_back(12);
    b.digits.push_back(128);
    // b.digits.push_back(25);
    a.mini_power=0;
    b.mini_power=0;

    
    // a.digits.clear();
    // b.digits.clear();
    // a.digits.push_back(4);
    // a.digits.push_back(43);
    // a.digits.push_back(154);
    // a.digits.push_back(0);

    // b.digits.push_back(140);
    // b.digits.push_back(128);

    // a.mini_power=0;
    // b.mini_power=0;
    // Normalize(a, b);
    // long_Division(a, b);

    // b.digits.clear();
    // b.digits.push_back(128);

    // // a.mini_power=0;
    // // b.mini_power=0;
    //Normalize(a,b);
    number ans = sub(a, b);
    cout<<ans.is_negative<<" ";
    cout << "ans ";
    for(auto x: ans.digits)
    {
        cout << x << " ";
    }
    cout << endl;
}
// 101 190 192 251 145 247
// 11 211 134 236 125 211