#include<arithmetic.hpp>

//Assuming X to be larger than Y
//q and r are quotient and remainder respectively
//Reverse digits of X and Y
number long_Division(number X, number Y)
{
	//reverse(X.digits.begin(),X.digits.end());
	//reverse(Y.digits.begin(),Y.digits.end());
	ll k = X.digits.size();
	ll l = Y.digits.size();

	//Normalization check 
	ll w = (long long)(log10(base)/log10(2.0));
	ll w_dash = 0;
	if(Y.digits[l-1] < pow(2, w-1))
	{
		number tmp;
		tmp.digits.push_back(1);
		tmp.mini_power = 0;
		while (Y.digits[l-1] < pow(2, w-1))
		{
			// Multiply both numbers X and Y by appropriate 2^w' where 0<=w'<w
			// tmp.digits[0] *= 2;
			// Y = multiply_karatsuba(Y, tmp);
			// w_dash ++;
		}
		// X = multiply_karatsuba(X, tmp);
	}
	
	number r, q; 
	for(ll i = 0; i<k ; i ++)
	{
		r.digits.push_back(X.digits[i]);
	}
	r.digits.push_back(0);
	for(ll i=k-l; i >=0 ; i--)
	{
		q.digits.push_back(0);
	}
	for(ll i=k-l; i >=0 ; i--)
	{
		q.digits[i] = floor((r.digits[i+l]*base + r.digits[i+l-1])/Y.digits[l-1]);
		if(q.digits[i]>= base)
		{
			q.digits[i] = base -1;
		}
		ll carry = 0;
		for(ll j = 0; j <= l-1;j++)
		{
			ll tmp = r.digits[i+j] - (q.digits[i] * Y.digits[j]) + carry;
			carry = tmp/base;
			r.digits[i+j] = tmp%base;
		}
		r.digits[i+l] =  r.digits[i+l] + carry;
		while(r.digits[i+l] < 0) // Will run atmost twice
		{
			carry = 0;
			for(ll j=0; j <= l-1 ; j++)
			{
				ll tmp = r.digits[i+j] - ( Y.digits[j]) + carry;
				carry = tmp/base;
				r.digits[i+j] = tmp%base;
			}
			r.digits[i+l] = r.digits[i+l] + carry;
			q.digits[i] = q.digits[i] - 1;
		}
	}
	//Shayad Quotient bs chahitye hai... normalization ki wjah se quotient mai koi fark ni aaega
}