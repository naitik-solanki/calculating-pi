#include"arithmetic.hpp"

number mult(number X, number Y, ll base)
{
	ll k = X.digits.size();
	ll l = Y.digits.size();
	reverse(X.digits.begin(),X.digits.end());
	reverse(Y.digits.begin(),Y.digits.end());
	number ans;
	ans.is_negative = false;
	ans.mini_power = X.mini_power + Y.mini_power;
	for(ll i=0; i <= k+l-1;i++)
	{
		ans.digits.push_back(0);
	}
	for(ll i=0;i <= k-1;i++)
	{
		ll carry =0;
		for(ll j=0;j<=l-1;j++)
		{
			ll tmp = X.digits[i]*Y.digits[j] + ans.digits[i+j] + carry;
			pair<ll , ll> Quorem = quorem(tmp, base);
			carry = Quorem.first;
			ans.digits[i+j] = Quorem.second;
		}
		ans.digits[i+l] = carry;
	}
	while(ans.digits.size() > 1)
	{
		if(ans.digits.back() == 0)
		{
			ans.digits.pop_back();
		}
		else	break;
	}
	reverse(ans.digits.begin(),ans.digits.end());
	while(ans.digits.size() > 1)
	{
		if(ans.digits.back() == 0)
		{
			ans.digits.pop_back();
			ans.mini_power++;
		}
		else	break;
	}
	return(ans);
}