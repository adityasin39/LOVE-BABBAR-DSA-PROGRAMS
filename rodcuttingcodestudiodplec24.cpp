// using recursion
// #include<bits/stdc++.h>
// int solve(vector<int>& price, int n, int len)
// {
// 	if(len==0) return 0;
// 	if(n==0) return price[0]*len;
// 	int pick=INT_MIN;
// 	if(len>=n+1) pick=price[n]+solve(price,n,len-(n+1));
// 	int notpick=solve(price,n-1,len);
// 	return max(pick,notpick);
// }
// int cutRod(vector<int> &price, int n)
// {
// 	return solve(price,n-1,n);
// }
// using memoization
// #include<bits/stdc++.h>
// int solve(vector<int>& price, int n, int len, vector<vector<int>>& dp)
// {
// 	if(len==0) return 0;
// 	if(n==0) return price[0]*len;
// 	if(dp[n][len]!=-1) return dp[n][len];
// 	int pick=INT_MIN;
// 	if(len>=n+1) pick=price[n]+solve(price,n,len-(n+1),dp);
// 	int notpick=solve(price,n-1,len,dp);
// 	return dp[n][len]=max(pick,notpick);
// }
// int cutRod(vector<int> &price, int n)
// {
// 	vector<vector<int>> dp(n,vector<int>(n+1,-1));
// 	return solve(price,n-1,n,dp);
// }
// using tabulation
// #include<bits/stdc++.h>
// int cutRod(vector<int> &price, int n)
// {
// 	vector<vector<int>> dp(n,vector<int>(n+1,-1));
// 	for(int i=0;i<n;i++) dp[i][0]=0;
// 	for(int i=0;i<=n;i++) dp[0][i]=price[0]*i;
// 	for(int i=1;i<n;i++)
// 	{
// 		for(int j=1;j<=n;j++)
// 		{
// 			int pick=INT_MIN;
// 			if(j>=i+1) pick=price[i]+dp[i][j-(i+1)];
// 			int notpick=dp[i-1][j];
// 			dp[i][j]=max(pick,notpick);
// 		}
// 	}
// 	return dp[n-1][n];
// }
// using space optimization
#include<bits/stdc++.h>
int cutRod(vector<int> &price, int n)
{
	vector<int> prev(n+1,0);
	for(int i=0;i<=n;i++) prev[i]=price[0]*i;
	for(int i=1;i<n;i++)
	{
		vector<int> curr(n+1,0);
		for(int j=1;j<=n;j++)
		{
			int pick=INT_MIN;
			if(j>=i+1) pick=price[i]+curr[j-(i+1)];
			int notpick=prev[j];
			curr[j]=max(pick,notpick);
		}
		prev=curr;
	}
	return prev[n];
}