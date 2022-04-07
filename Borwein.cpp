#include"arithmetic.hpp"
number borwein(int prec_base,ll base)//this is the direct implementation of the algorithm
{
    ll no_ofiterations = log2(prec_base) + 3; 
    number two;
    two.is_negative=0;
    two.digits.push_back(2);
    two.mini_power=0;
    number one;
    one.is_negative=0;
    one.digits.push_back(1);
    one.mini_power=0;
    number an = sq_root(two,prec_base, base);
    number bn = sub(two ,two, base);
    number pn = add(two,an, base);
    int i=0;
    while(i < no_ofiterations)
    {
        //cout << "Ruko Vai ... " << endl;
        number sqrt_a = sq_root(an,prec_base, base);
        bn= long_Division(mult(add(one,bn, base),sqrt_a, base),add(an,bn, base),prec_base, base);
        an = long_Division(add(sqrt_a,long_Division(one,sqrt_a,prec_base, base), base),two,prec_base, base);
        number temp = mult(mult(add(one,an, base),pn, base),bn, base);
        pn = long_Division(mult(mult(add(one,an, base),pn, base),bn, base),add(one,bn, base),prec_base, base);
        i++;
    }
    
    return pn;
}