#include"arithmetic.hpp"
number borwein()
{
    number two;
    two.is_negative=0;
    two.digits.push_back(2);
    two.mini_power=0;
    number one;
    two.is_negative=0;
    two.digits.push_back(1);
    two.mini_power=0;
    number an = sq_root(two,2);
    number bn = sub(two ,two);
    number pn = add(two,an);
    int i=0;
    while(i<10)
    {
        number sqrt_a = sq_root(an,2);
        bn= long_Division( multiply_Karatsuba( add(one,bn),sqrt_a),add(an,bn),2);
        an = long_Division(add(sqrt_a,long_Division(one,sqrt_a,2)),two,2);
        pn =long_Division( multiply_Karatsuba( multiply_Karatsuba( add(one,an),pn),bn),add(one,bn),2);
        i++;
    }
    return pn;
}