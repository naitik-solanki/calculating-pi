#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct number
{
    vector<int>digits;
    int mini_power;
    bool is_negative;
};
number add(number a,number b, ll base);
number sub(number a,number b, ll base);
number multiply_Karatsuba(number X, number Y, ll base);
number long_Division(number X, number Y,int precision, ll base);
void Normalize(number &X, number &Y, ll base);
number sq_root(number a,int precision, ll base);
number borwein(int precision, ll base);

number multiply_Singlenum(number num1, number num2, ll base);
ll equal_Length(number &num1, number &num2);
pair<ll, ll> quorem(ll a, ll base);
void truncate(number &n, int precision);
ll precision_in_base(ll precision, ll my_base);
number convert_toDecimal(number n, ll base);