#include<bits/stdc++.h>
using namespace std;
#define base 256
typedef long long ll;
class number
{
    public:
    vector<int>digits;
    int mini_power;
    
};
number add(number a,number b);
number sub(number a,number b);
number multiply_Karatsuba(number X, number Y);

number multiply_Singlenum(number num1, number num2);
ll equal_Length(number &num1, number &num2);