#include"arithmetic.hpp"
number borwein(int precision)
{
    number two;
    two.is_negative=0;
    two.digits.push_back(2);
    two.mini_power=0;
    number one;
    one.is_negative=0;
    one.digits.push_back(1);
    one.mini_power=0;
    // cout << "two " << endl;
    // cout << "an mini power - " << two.mini_power << endl;
    // for(auto x: two.digits)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    number an = sq_root(two,precision);
    number bn = sub(two ,two);
    number pn = add(two,an);
    // cout << "an - " << endl;
    // cout << "an mini power - " << an.mini_power << endl;
    // for(auto x: an.digits)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    int i=0;
    cout << "phuch gye yha tk" << endl;
    while(i<10)
    {
        cout << "1" << endl;
        number sqrt_a = sq_root(an,precision);
        // cout << "sqrt - " << endl;
        // cout << "sqrt mini power - " << sqrt_a.mini_power << endl;
        // for(auto x: sqrt_a.digits)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        //cout << "2" << endl;
        bn= long_Division(multiply_Karatsuba(add(one,bn),sqrt_a),add(an,bn),precision);
        //cout << "sqrt_a " << endl;
        //cout << "mini power "<< sqrt_a.mini_power << endl;
        // for(auto x: sqrt_a.digits)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // cout << "3" << endl;
        an = long_Division(add(sqrt_a,long_Division(one,sqrt_a,2)),two,precision);
        //cout << "4" << endl;
        number temp = multiply_Karatsuba(multiply_Karatsuba(add(one,an),pn),bn);
        //cout << "temp " << endl;
       // cout << "mini power "<< temp.mini_power << endl;
        // for(auto x: temp.digits)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        pn =long_Division(multiply_Karatsuba(multiply_Karatsuba(add(one,an),pn),bn),add(one,bn),precision);
        //cout << "5" << endl;
        i++;
    }
    return pn;
}