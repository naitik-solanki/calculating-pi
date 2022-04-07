#include"arithmetic.hpp"

ll precision_in_base(ll precision, ll my_base) //Argument mai wrt base 10 hai
{
    return(ceil(precision * log2(10))/my_base);
}


void Normalize(number &X, number &Y,ll base)
{
	//Normalization check
	//Square of msb Y should be greater than equal to base for division algo to work
	if(Y.digits[0]*Y.digits[0] < base)
	{
		number tmp, tmp1;
		tmp1 = Y;
		tmp.digits.push_back(1);
		tmp.mini_power = 0;
		while (tmp1.digits[0]*tmp.digits[0] < base)
		{
			tmp.digits[0]*=2;
			tmp1 = mult(Y, tmp, base);
		}
		//Multiplying X and Y by appropriate 2's power to normalize the inputs
		X = mult(X, tmp, base);
		Y = mult(Y, tmp, base);
		return;
	}
	return;
}

pair<ll, ll> quorem(ll a,ll base)
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

//For making num1 and num2 of equal length in terms of digits vector size
ll equal_Length(number &num1, number &num2)
{
	ll len1 = num1.digits.size();
	ll len2 = num2.digits.size();
	if(len1 < len2)
	{
		for(ll i =0;i<len2-len1;i++)
		{
			num1.digits.insert(num1.digits.begin(), 0);
		}
		return(len2);
	}
	else if (len2 < len1)
	{
		for(ll i =0;i<len1-len2;i++)
		{
			num2.digits.insert(num2.digits.begin(), 0);
		}
		return(len1);
	}
	return(len2);
}

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
