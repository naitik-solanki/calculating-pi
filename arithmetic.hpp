#include<bits/stdc++.h>
using namespace std;
#define base 256
typedef long long ll;
class number
{
    public:
    vector<int>digits;
    int mini_power;
    bool is_negative;
};
number add(number a,number b);
number sub(number a,number b);
number multiply_Karatsuba(number X, number Y);
number long_Division(number X, number Y,int precision);
void Normalize(number &X, number &Y);
number sq_root(number a,int precision);
number borwein(int precision);
number multiply_Singlenum(number num1, number num2);
ll equal_Length(number &num1, number &num2);
pair<ll, ll> quorem(ll a);