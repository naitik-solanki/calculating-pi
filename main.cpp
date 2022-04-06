#include"arithmetic.hpp"
int main()
{
    number a,b;
    
    a.digits.push_back(22);
    a.digits.push_back(74);
    a.digits.push_back(82);
    a.digits.push_back(148);
    a.digits.push_back(255);
    b.digits.push_back(4);
    b.digits.push_back(184);
    b.digits.push_back(164);
    b.digits.push_back(174);
    b.digits.push_back(25);
    b.digits.push_back(0);
    b.digits.push_back(0);
    b.digits.push_back(3);
    b.digits.push_back(128);


    // b.digits.push_back(25);
    // b.digits.push_back(153);
    // b.digits.push_back(153);
    // b.digits.push_back(153);

    

    // b.digits.push_back(25);
    a.mini_power=-4;
    b.mini_power=-8;

    
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
    number ans = long_Division(a,b,2);
    cout<<ans.mini_power<<" ";
    cout << "ans ";
    for(auto x: ans.digits)
    {
        cout << x << " ";
    }
    cout << endl;
}
// 101 190 192 251 145 247
// 11 211 134 236 125 211