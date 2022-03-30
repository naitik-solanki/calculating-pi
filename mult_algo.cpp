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

number multiply_Singlenum(number num1, number num2) //Arguments wll contain only single entry
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

number multiply_Karatsuba(number X, number Y)
{
	//Making the vectors of equal length
	//int power = equal_Mini_Power(X, Y);
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
    if (n == 1) return multiply_Singlenum(X, Y);

    // for(auto x:X.digits)
    // {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
	//Splitting the number into two
	int split;
	if(n%2 == 1)	split = (n+1)/2;
	else	split = (n)/2; 
	// cout << "Split - " << split << endl;
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
	// first_halfX.digits.assign(X.digits.begin(), X.digits.begin() + split);
	// second_halfX.digits.assign(X.digits.begin() + split, X.digits.end());

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
	// first_halfY.digits.assign(Y.digits.begin(), Y.digits.begin() + split);
	// second_halfY.digits.assign(Y.digits.begin() + split , Y.digits.end());

	// cout<<"First half of X ";
	// for(auto x:first_halfX.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
	// cout<<"Second half of X ";
	// for(auto x:second_halfX.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
	// cout<<"First half of Y ";
	// for(auto y:first_halfY.digits)
    // {
    // 	cout<<y<<" ";
    // }
    // cout<<endl;
	// cout<<"Second half of Y ";
	// for(auto y:second_halfY.digits)
    // {
    // 	cout<<y<<" ";
    // }
    // cout<<endl;
	number P = multiply_Karatsuba(first_halfX, first_halfY);
    number Q = multiply_Karatsuba(second_halfX, second_halfY);
	number temp1 = add(first_halfX, second_halfX);
	number temp2 = add(first_halfY, second_halfY);
    number prod = multiply_Karatsuba(temp1, temp2);
	// cout<<"prod ";
	// for(auto x:prod.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
	number temp = sub(prod, P);
	number R = sub(temp, Q);
    //Forming the answer.... by P*B^2m + R*B^m + Q ...
	// cout << "Split - " << split << endl;
	split = n/2;
	P.mini_power =P.mini_power +  2*split;
	R.mini_power = R.mini_power + split;	
	// cout<<P.mini_power<<" "<<R.mini_power<<endl;
	// cout<<"P ";
	// for(auto x:P.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
	// cout<<"Q ";
	// for(auto x:Q.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
	// cout<<"R ";
	// for(auto x:R.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
	number Z = add(Q, R);
	// cout << "Z digits ";
	// for(auto x:Z.digits)
    // {
    // 	cout<<x<<" ";
    // }
    // cout<<endl;
	ans = add(Z, P);
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