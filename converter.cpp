#include"arithmetic.hpp"
number num_tobase10(ll n)
{
	number ans;
	ans.is_negative = false;
	ans.mini_power = 0;
	while(n)
	{
		ans.digits.push_back(n%10);
		n/=10;
	}
	reverse(ans.digits.begin(), ans.digits.end());
	return(ans);
}

string convert_toDecimal(number n, int precision,ll base)
{
	number B;
	string final;
	number ans;
	ans.is_negative=false;
	ans.mini_power=0;
	ans.digits.push_back(0);
	B = num_tobase10(base);
	number one;
	one.digits.push_back(1);
	one.is_negative = false;
	one.mini_power = 0;
	ll pos_size = n.digits.size()+n.mini_power; //For Mini Power.. as it will be called at last then it will be negative
	number temp = one;
	for(int i=pos_size-1 ;i>=0;i--)
	{
		ans = add(ans,mult(num_tobase10(n.digits[i]),temp, 10), 10);
		temp = mult(temp, B, 10);
	}

	number base_inverted = long_Division(one, B, precision, 10);
	ll neg_size = n.digits.size();
	temp = base_inverted;
	for(int i= pos_size;i<n.digits.size();i++)
	{
		ans = add(ans,mult(num_tobase10(n.digits[i]),temp, 10), 10);
		temp = mult(temp, base_inverted, 10);
	}
	for(int i= 0 ; i<ans.digits.size()+ans.mini_power;i++)
	{
		final.push_back('0'+ans.digits[i]);
	}
	final.push_back('.');
	for(int i=ans.digits.size()+ans.mini_power; i<ans.digits.size();i++)
	{
		final.push_back('0'+ans.digits[i]);
	}
	return final;
}