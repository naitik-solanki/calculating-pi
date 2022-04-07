#include"arithmetic.hpp"



number multiply_Singlenum(number num1, number num2,ll base) //Arguments wll contain only single entry
{
	number ans;
	if((num1.digits[0] * num2.digits[0])/base != 0)
	{
		ans.digits.push_back((num1.digits[0] * num2.digits[0])/base);
	}
	ans.digits.push_back((num1.digits[0] * num2.digits[0])%base);
	ans.mini_power = num1.mini_power + num2.mini_power;
	return(ans);
}

number multiply_Karatsuba(number X, number Y,ll base)
{
	//Making the vectors of equal length
	int n = equal_Length(X, Y);
	number ans;
	if(X.is_negative && Y.is_negative)	ans.is_negative = false;
	else if(X.is_negative || Y.is_negative)	ans.is_negative = true; 
	else	ans.is_negative = false;
    //Base cases
    if(n == 0)
	{
		ans.digits.push_back(0);
		ans.mini_power = 0;
		return(ans);
	}
    if (n == 1) return multiply_Singlenum(X, Y, base);

	//Calculating the split and splitting the vectors into two halves for both the numbers
	int split;
	if(n%2 == 1)	split = (n+1)/2;
	else	split = (n)/2; 
	number first_halfX, second_halfX;
	first_halfX.mini_power = X.mini_power;
	second_halfX.mini_power = X.mini_power;
	for(ll i=0;i<split;i++)
	{
		first_halfX.digits.push_back(X.digits[i]);
	}
	for(ll i=split;i<n;i++)
	{
		second_halfX.digits.push_back(X.digits[i]);
	}
	number first_halfY, second_halfY;
	first_halfY.mini_power = Y.mini_power;
	second_halfY.mini_power = Y.mini_power;
	for(ll i=0;i<split;i++)
	{
		first_halfY.digits.push_back(Y.digits[i]);
	}
	for(ll i=split;i<n;i++)
	{
		second_halfY.digits.push_back(Y.digits[i]);
	}
	//Recursive calls to calculate P, Q and R for the main equation
	//P*B^2m + R*B^m + Q ..... m - split value
	number P = multiply_Karatsuba(first_halfX, first_halfY, base);
    number Q = multiply_Karatsuba(second_halfX, second_halfY, base);
	number temp1 = add(first_halfX, second_halfX, base);
	number temp2 = add(first_halfY, second_halfY, base);
    number prod = multiply_Karatsuba(temp1, temp2, base);
	number temp = sub(prod, P, base);
	number R = sub(temp, Q, base);
	split = n/2;
	P.mini_power =P.mini_power +  2*split;
	R.mini_power = R.mini_power + split;	
	number Z = add(Q, R, base);
	ans = add(Z, P, base);

	//Removing leading and trailing zeroes from the answer
	int i= ans.digits.size();
	while(i != 1)
	{
		if(ans.digits[i - 1] == 0)
		{
			ans.digits.pop_back();
			ans.mini_power++;
			i--;
		}
		else	break;
	}
	reverse(ans.digits.begin(),ans.digits.end());
	while(ans.digits.size() != 1)
	{
		if(ans.digits[ans.digits.size() - 1] == 0)
		{
			ans.digits.pop_back();
		}
		else	break;
	}
	reverse(ans.digits.begin(),ans.digits.end());
	return(ans);
}