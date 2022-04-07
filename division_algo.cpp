#include"arithmetic.hpp"


//Assuming X to be larger than Y
//q and r are quotient and remainder respectively
//Considering X/Y
number long_Division(number X, number Y,int precision,ll base)
{
	Normalize(X, Y, base);
	int temp = Y.mini_power;
	if(Y.mini_power>0)
	{
		temp=0;
	}
	while (Y.mini_power<0)
	{
		X.digits.push_back(0);
		Y.mini_power++;
	}

	if(precision)// to add precision , we add zeros so that we can get the quotient till that digit 
	{
		for(int i=0;i<precision;i++)
		{
			X.digits.push_back(0);
		}
		X.mini_power-=(precision);
		number q=long_Division(X,Y,0, base);
		int i=0;
		while((abs(q.mini_power) > precision) && (q.mini_power<0))
		{
			q.digits.pop_back();
			q.mini_power++;
			i++;
		}
		return(q);
	}
	while(X.mini_power>0)
	{
		X.digits.push_back(0);
		X.mini_power--;
	}
	ll k = X.digits.size();
	ll l = Y.digits.size();
	reverse(X.digits.begin(),X.digits.end());
	reverse(Y.digits.begin(),Y.digits.end());
	number r, q;
	r.mini_power = 0;
	q.mini_power = X.mini_power - Y.mini_power;
	for(ll i = 0; i<k ; i ++)
	{
		r.digits.push_back(X.digits[i]);
	}
	r.digits.push_back(0);
	for(ll i=k-l; i >=0 ; i--)
	{
		q.digits.push_back(0);
	}
	//Main Algorithm
	for(ll i=k-l; i >=0 ; i--)
	{
		q.digits[i] = floor((float)(r.digits[i+l]*base + r.digits[i+l-1])/(Y.digits[l-1]));
		if(q.digits[i]>= base)
		{
			q.digits[i] = base -1;
		}
		ll carry = 0;
		for(ll j = 0; j <= l-1;j++)
		{
			ll tmp = r.digits[i+j] - (q.digits[i] * Y.digits[j]) + carry;
			pair<ll, ll> Quo_rem = quorem(tmp, base);
			carry = Quo_rem.first;
			r.digits[i+j] = Quo_rem.second;
		}
		r.digits[i+l] =  r.digits[i+l] + carry;
		while(r.digits[i+l] < 0) // Will run atmost twice
		{
			carry = 0;
			for(ll j=0; j <= l-1 ; j++)
			{
				ll tmp = r.digits[i+j] + ( Y.digits[j]) + carry;
				pair<ll, ll> Quo_rem = quorem(tmp, base);
				carry = Quo_rem.first;
				r.digits[i+j] = Quo_rem.second;
			}
			r.digits[i+l] = r.digits[i+l] + carry;
			q.digits[i] = q.digits[i] - 1;
		}
	}

	//Removing leading zeroes..
	while(q.digits.size() > 1)
	{
		if(q.digits.back() == 0)
		{
			q.digits.pop_back();
		}
		else	break;
	}
	reverse(q.digits.begin(),q.digits.end());
	return q;
}