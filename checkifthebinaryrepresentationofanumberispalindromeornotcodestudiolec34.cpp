#include <bits/stdc++.h> 
using namespace std;
bool isPalindrome(vector<int> &a, int i) // in case of vector & works
{
	if(i>a.size()/2) return true;
	if(a[i]==a[a.size()-i-1]) 
	{
		i++;
		return isPalindrome(a,i);
	}
	else return false;
}
bool checkPalindrome(long long N)
{
	vector<int> a;
	while(N)
	{
		a.push_back(N%2);
		N=N/2;
	}
	int i=0;
	bool res=isPalindrome(a,i);
	return res;
}