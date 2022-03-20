#include"addition.hpp"
number add(number &a,number &b)
{

   if(a.mini_power!=b.mini_power)
    {
       if(a.mini_power>b.mini_power)
       {
            for(int i=0;i<a.mini_power-b.mini_power;i++)
            {
                a.digits.push_back(0);
                a.mini_power--;
            }    
       }
       else
       {
            for(int i=0;i<b.mini_power-a.mini_power;i++)
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
    for(;p>=0,q>=0;p--,q--)
    {
        cout<<a.digits[p]<<' '<<b.digits[q]<<" "<<endl;
        ans.digits.push_back((a.digits[p]+b.digits[q]+carry)%base);
        carry = (a.digits[p]+b.digits[q]+carry)/base;
    }
    while(p!=-1)
    {
        ans.digits.push_back((a.digits[p]+carry)%base);
        carry = (a.digits[p]+carry)/base;
        p--;
    }
    while(q!=-1)
    {
        ans.digits.push_back((b.digits[q]+carry)%base);
        carry = (b.digits[q]+carry)/base;
        q--;
    }
    reverse(ans.digits.begin(),ans.digits.end());
    return ans;
}