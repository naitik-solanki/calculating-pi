#include"arithmetic.hpp"
number add(number a,number b,ll base)
{

   if(a.mini_power!=b.mini_power)
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
    //cout<<a.mini_power<<' '<<b.mini_power<<' '<<ans.mini_power<<endl;
    int carry = 0;
    int p=a.digits.size()-1,q=b.digits.size()-1;
    for(;(p>=0) &&(q>=0);p--,q--)
    {
       // cout<<a.digits[p]<<' '<<b.digits[q]<<" "<<endl;
        ans.digits.push_back((a.digits[p]+b.digits[q]+carry)%base);
        carry = (a.digits[p]+b.digits[q]+carry)/base;
    }
    // for(auto x:ans.digits)
    // {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    while(p>-1)
    {
        ans.digits.push_back((a.digits[p]+carry)%base);
        carry = (a.digits[p]+carry)/base;
        p--;
    }
    while(q>-1)
    {
        ans.digits.push_back((b.digits[q]+carry)%base);
        carry = (b.digits[q]+carry)/base;
        q--;
    }
    if(carry)
    {
        ans.digits.push_back(carry);
    }
    for(int i=ans.digits.size()-1;i>0;i--)
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
    // cout<<"a ";
	// for(auto x:a.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout << endl;
    // cout<<"b ";
	// for(auto x:b.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
    // cout<<"add inter ";
	// for(auto x:ans.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
    return ans;
}