#include"arithmetic.hpp"

//Assuming X to be larger than Y
//q and r are quotient and remainder respectively
//Reverse digits of X and Y

void Normalize(number &X, number &Y)
{
	//Normalization check
	ll w = (long long)(log10(base)/log10(2.0));
	//cout << "w - " << w << endl;
	// ll w_dash = 0;
	if(Y.digits[0] < pow(2, w-1))
	{
		number tmp, tmp1;
		tmp1 = Y;
		tmp.digits.push_back(1);
		tmp.mini_power = 0;
		while (tmp1.digits[0] < pow(2, w-1))
		{
			//Multiply both numbers X and Y by appropriate 2^w' where 0<=w'<w
			tmp.digits[0]*=2;
			tmp1 = multiply_Karatsuba(Y, tmp);
			//w_dash ++;
		}
		//cout << "Multiplied with - " << tmp.digits[0] << endl;
		X = multiply_Karatsuba(X, tmp);
		Y = multiply_Karatsuba(Y, tmp);
		return;
	}
	return;
}

pair<ll, ll> quorem(ll a)
{
	pair<ll, ll> ans;
	if(a < 0)
	{
		if(a%base == 0)
		{
			ans.first = a/base;
			ans.second = 0;
			return(ans);
		}
		else
		{
			ans.first = -(abs(a)/base + 1);
			ans.second = (abs(a)/base + 1)*(base) - abs(a);
			return(ans);
		}
	}
	else
	{
		ans.first = a/base;
		ans.second = a%base;
		return(ans);
	}
	return(ans);
}

//Considering X/Y
number long_Division(number X, number Y)
{
	ll k = X.digits.size();
	ll l = Y.digits.size();
	// cout<<"X ";
	// for(auto x:X.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
	// cout<<"Y ";
	// for(auto x:Y.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
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
	// for(auto x: Y.digits)
	// {
	// 	cout << x << " ";
	// }
	// cout << endl;
	for(ll i=k-l; i >=0 ; i--)
	{
		q.digits.push_back(0);
	}
	for(ll i=k-l; i >=0 ; i--)
	{
		q.digits[i] = floor((float)(r.digits[i+l]*base + r.digits[i+l-1])/(Y.digits[l-1]));
		//cout << "Random Q - " << q.digits[i] << " firstwala " << (r.digits[i+l]*base) <<" Secondwala "<< (r.digits[i+l-1])<< endl;
		if(q.digits[i]>= base)
		{
			q.digits[i] = base -1;
		}
		ll carry = 0;
		for(ll j = 0; j <= l-1;j++)
		{
			ll tmp = r.digits[i+j] - (q.digits[i] * Y.digits[j]) + carry;
			pair<ll, ll> Quo_rem = quorem(tmp);
			carry = Quo_rem.first;
			r.digits[i+j] = Quo_rem.second;
			// carry = tmp/base;
			//cout << "temp - " << tmp << endl;
			// r.digits[i+j] = modu(tmp);
			//cout << "Changed r1 - " << r.digits[i+j] << endl;
		}
		r.digits[i+l] =  r.digits[i+l] + carry;
		while(r.digits[i+l] < 0) // Will run atmost twice
		{
			carry = 0;
			for(ll j=0; j <= l-1 ; j++)
			{
				ll tmp = r.digits[i+j] - ( Y.digits[j]) + carry;
				pair<ll, ll> Quo_rem = quorem(tmp);
				carry = Quo_rem.first;
				r.digits[i+j] = Quo_rem.second;
				// carry = tmp/base;
				// r.digits[i+j] = modu(tmp);
				//cout << "Changed r2 - " << r.digits[i+j] << endl;
			}
			r.digits[i+l] = r.digits[i+l] + carry;
			q.digits[i] = q.digits[i] - 1;
			//cout << "Changed r3 - " << r.digits[i+l] << endl;
		}
	}
	//Removing leading zeroes..
	while(q.digits.size() != 1)
	{
		if(q.digits[q.digits.size() - 1] == 0)
		{
			q.digits.pop_back();
		}
		else	break;
	}
	reverse(q.digits.begin(),q.digits.end());
	return q;
}