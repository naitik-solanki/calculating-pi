#include"addition.hpp"
int main()
{
    vector<number>a;
    vector<number>b;
    number temp;
    temp.digit=247;
    temp.power=-4;
    a.push_back(temp);
    temp.digit=145;
    temp.power++;
    a.push_back(temp);
    temp.digit=251;
    temp.power++;
    a.push_back(temp);
    temp.digit=192;
    temp.power++;
    a.push_back(temp);
    temp.digit=190;
    temp.power++;
    a.push_back(temp);
    temp.digit=101;
    temp.power++;
    a.push_back(temp);

    


    temp.digit=211;
    temp.power=-2;
    b.push_back(temp);
    temp.digit=125;
    temp.power++;
    b.push_back(temp);
    temp.digit=236;
    temp.power++;
    b.push_back(temp);
    temp.digit=134;
    temp.power++;
    b.push_back(temp);
    temp.digit=211;
    temp.power++;
    b.push_back(temp);
    temp.digit=11;
    temp.power++;
    b.push_back(temp);

    vector<number> t=add(a,b);
    for(auto x:t)
    {
        cout<<x.digit<<' ';
    }
    cout<<endl;
}
//        101 190 192 251 145 247
// 11 211 134 236 125 211