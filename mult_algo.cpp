#include"arithmetic.hpp"

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

// ll equal_Mini_Power(number &a, number &b)
// {
// 	if(a.mini_power!=b.mini_power)
//     {
//        if(a.mini_power>b.mini_power)
//        {
//             for(int i=0;i<a.mini_power-b.mini_power;i++)
//             {
//                 a.digits.push_back(0);
//                 a.mini_power--;
//             }    
//        }
//        else
//        {
//             for(int i=0;i<b.mini_power-a.mini_power;i++)
//             {
//                 b.digits.push_back(0);
//                 b.mini_power--;
//             }  
//        }
//     }
// 	return(a.mini_power);
// }

number multiply_Singlenum(number num1, number num2) //Arguments wll contain only single entry
{
	number ans;
	ans.digits.push_back((num1.digits[0] * num2.digits[0])/base);
	ans.digits.push_back((num1.digits[0] * num2.digits[0])%base);
	ans.mini_power = num1.mini_power + num2.mini_power;
	return(ans);
}

number multiply_Karatsuba(number X, number Y)
{
	//Making the vectors of equal length
	//int power = equal_Mini_Power(X, Y);
	int n = equal_Length(X, Y);
	number ans;

    //Base cases
    if(n == 0)
	{
		ans.digits.push_back(0);
		ans.mini_power = 0;
		return(ans);
	}
    if (n == 1) return multiply_Singlenum(X, Y);

    //Splitting the number into two
	int split = n/2;   
	number first_halfX, second_halfX;
	first_halfX.mini_power = X.mini_power;
	second_halfX.mini_power = X.mini_power;
	auto it = next(X.digits.begin(), split - 1);
	copy(X.digits.begin(), it, back_inserter(first_halfX.digits));
	it++;
	copy(it, X.digits.end(), back_inserter(second_halfX.digits));

	number first_halfY, second_halfY;
	first_halfY.mini_power = Y.mini_power;
	second_halfY.mini_power = Y.mini_power;
	it = next(Y.digits.begin(), split - 1);
	copy(Y.digits.begin(), it, back_inserter(first_halfY.digits));
	it++;
	copy(it, Y.digits.end(), back_inserter(second_halfY.digits));

	number P = multiply_Karatsuba(first_halfX, first_halfY);
    number Q = multiply_Karatsuba(second_halfX, second_halfY);
    number R = multiply_Karatsuba(add(first_halfX, second_halfX), add(first_halfY, second_halfY));
    
    //Forming the answer.... by P*B^2m + R*B^m + Q ...
	P.mini_power = P.mini_power + 2*split;
	R.mini_power = R.mini_power + split;
	ans = add(add(Q, R), P);
	return(ans);
}