#include<iostream>
#include<vector>
//#include<algorithm>
#include<iterator>
using namespace std;
#define base 256
typedef long long ll;
class number
{
    public:
    vector<int>digits;
    int mini_power;
    
};
number add(number &a,number&b);
number sub(number &a,number &b);
number multiply_karatsuba(number &a,number &b);