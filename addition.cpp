#include"arithmetic.hpp"
number add(number a,number b,ll base)
{
   if(a.mini_power!=b.mini_power)//we make both the numbe of same size after decimal point
    {
       if(a.mini_power>b.mini_power)
       {
            while(a.mini_power>b.mini_power)
            {
                a.digits.push_back(0);
                a.mini_power--;
            }    
       }
       else
       {
            while(b.mini_power>a.mini_power)
            {
                b.digits.push_back(0);
                b.mini_power--;
            }  
       }
    }
    number ans;
    ans.mini_power=a.mini_power;
    int carry = 0;
    int p=a.digits.size()-1,q=b.digits.size()-1;
    for(;(p>=0) &&(q>=0);p--,q--)//this loop adds the ith digit of p to ith digit of q
    {
        ans.digits.push_back((a.digits[p]+b.digits[q]+carry)%base);
        carry = (a.digits[p]+b.digits[q]+carry)/base;
    }
    while(p>-1)// if number of digits in p>number of digits in q, the digits left will be added to final answer here 
    {
        ans.digits.push_back((a.digits[p]+carry)%base);
        carry = (a.digits[p]+carry)/base;
        p--;
    }
    while(q>-1) // vice verse of the above
    {
        ans.digits.push_back((b.digits[q]+carry)%base);
        carry = (b.digits[q]+carry)/base;
        q--;
    }
    if(carry)//adding the last carry to my answer
    {
        ans.digits.push_back(carry);
    }
    for(int i=ans.digits.size()-1;i>0;i--)//removing preceding zeros for efficiency
    {
        if(ans.digits[i]==0)
        {
            ans.digits.pop_back();
        }
        else
        {
            break;
        }
    }
    reverse(ans.digits.begin(),ans.digits.end());
    return ans;
}