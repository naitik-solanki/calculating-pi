#include"addition.hpp"
vector<number> add(vector<number> &a,vector<number> &b)
{
    vector<number>final;
    int carry=0;
    int p=0,q=0;
    number cur;
    for(;p<a.size() && q<b.size();)
    {
        if(a[p].power==b[q].power)
        {
            cur.digit=((a[p].digit+b[q].digit+carry)%base);
            carry = (a[p].digit+b[q].digit+carry)/base;
            cur.power=a[p].power;
            p++;
            q++;
            final.push_back(cur);
        }
        else if(a[p].power<b[q].power)
        {
            cur.digit=((a[p].digit+carry)%256);
            carry = (a[p].digit+carry)/256;
            cur.power=a[p].power;
            p++;
            final.push_back(cur);
        }
        else
        {
            cur.digit=((b[q].digit+carry)%base);
            carry = (b[q].digit+carry)/base;
            cur.power=b[q].power;
            q++;
            final.push_back(cur);
        }
    }
    while(p!=a.size())
    {
        cur.digit=((a[p].digit+carry)%base);
        carry = (a[p].digit+carry)/base;
        cur.power=a[p].power;
        p++;
        final.push_back(cur);
    }
    while(q!=b.size())
    {
        cur.digit=((b[q].digit+carry)%base);
        carry = (b[q].digit+carry)/base;
        cur.power=b[q].power;
        q++;
        final.push_back(cur);
    }
    return final;
}