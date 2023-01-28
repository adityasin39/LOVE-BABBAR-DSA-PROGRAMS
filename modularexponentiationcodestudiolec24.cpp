#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// modulo is used to bring the answer in the desired range.
	//(a mod m)+(b mod m)  mod m=a+b  mod m
//(a mod m)−(b mod m)  mod m=a−b  mod m
//(a mod m)⋅(b mod m)  mod m=a⋅b  mod m
// (a%m)%m =a%m matlab ek par kitne baar bhi lagao same hi aaega
	//(a mod m)+(b mod m) =(a+b)  mod m
//(a mod m)−(b mod m) =(a−b)  mod m
//(a mod m)⋅(b mod m) =(a⋅b)  mod m
// this is the fast exponentiation method which has the O(logn)
// e.g 2^10 as 10 is even so we can write 4^5 and as 5 is odd so we can 
// write 4*4^4 and so on
	int res=1;
	while(n)
	{
		if(n&1)// to check odd
		{
			res=(1LL*res*(x%m))%m; // 1LL is used to typecast into long long
			n=n-1;
                } 
				
				else {
                  x =(( 1LL*x%m) * (x%m))%m;
                  n = n >> 1; // same as n=n/2 but >> is faster
                }
        }
	return res;
}