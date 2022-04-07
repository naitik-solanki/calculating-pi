/* Printing decimal digits of pi and square root of any number */
/* Submitted by - Arin Awasthi(IMT2020081) and Naitiksinh Solanki(IMT2020051) */

#include"arithmetic.hpp"
/* We are using normal mult for computations as it is working faster for us than Karatsub Algorithm */
/* Karatsuba generally works faster for very very large numbers.. but in case of pi or root(2) numbers are not going that large*/
int main()
{
    ll option, length, my_base;
    cin >> option >> length >> my_base;
    // Length has been increased by 3 because due to precision error.. last two digits might differ with
    // the original answer.. 
    length+=4;
    ll base = 1;
    number ans;
    for(ll i=0;i< my_base;i++)
    {
        base *= 2;
    }
    // Calculating prec wrt the given base
    ll prec_base = precision_in_base(length,my_base);
    switch (option)
    {
        case(1):
            {
                ans = borwein(prec_base, base);
                cout << convert_toDecimal(ans, length-3, base) << endl;
                break;
            }
        case(2):
            {
                number a;
                a.digits.push_back(2);
                a.mini_power = 0;
                a.is_negative = false;
                ans = sq_root(a,prec_base, base);
                cout << convert_toDecimal(ans, length-3, base) << endl;
                break;
            }
        default:
            break;
    }
}