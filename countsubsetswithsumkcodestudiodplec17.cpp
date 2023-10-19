// using recursion
// #include<bits/stdc++.h>
// int solve(int idx, vector<int>& arr, int k)
// {
// 	if(k==0) return 1;
// 	if(idx==0) return arr[0]==k;
// 	int pick=0;
// 	if(k>=arr[idx]) pick=solve(idx-1,arr,k-arr[idx]);
// 	int notpick=solve(idx-1,arr,k);
// 	return pick+notpick;
// }
// int findWays(vector<int>& arr, int k)
// {
// 	int n=arr.size();
// 	return solve(n-1,arr,k);
// }
// using memoization
// #include<bits/stdc++.h>
// long long mod=1e9+7;
// int solve(int idx, vector<int>& arr, int k, vector<vector<int>>& dp)
// {
// 	if(k==0) return 1;
// 	if(idx==0) return arr[0]==k;
// 	if(dp[idx][k]!=-1) return dp[idx][k]%mod;
// 	long long pick=0;
// 	if(k>=arr[idx]) pick=solve(idx-1,arr,k-arr[idx],dp)%mod;
// 	long long notpick=solve(idx-1,arr,k,dp)%mod;
// 	return dp[idx][k]=(pick+notpick)%mod;
// }
// int findWays(vector<int>& arr, int k)
// {
// 	int n=arr.size();
// 	vector<vector<int>> dp(n,vector<int>(k+1,-1));
// 	return solve(n-1,arr,k,dp)%mod;
// }
// using tabulation
// #include<bits/stdc++.h>
// long long mod=1e9+7;
// int findWays(vector<int>& arr, int k)
// {
// 	int n=arr.size();
// 	vector<vector<int>> dp(n,vector<int>(k+1,0));
// 	for(int i=0;i<n;i++) dp[i][0]=1;
// 	if(arr[0]<=k) dp[0][arr[0]]=1;
// 	for(int i=1;i<n;i++)
// 	{
// 		for(int j=1;j<=k;j++)
// 		{
// 			long long pick=0;
// 			if(j>=arr[i]) pick=dp[i-1][j-arr[i]]%mod;
// 			long long notpick=dp[i-1][j]%mod;
// 			dp[i][j]=(pick+notpick)%mod;
// 		}
// 	}
// 	return dp[n-1][k];
// }
// space optimization
#include<bits/stdc++.h>
long long mod=1e9+7;
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<int> prev(k+1,0);
	prev[0]=1;
	if(arr[0]<=k) prev[arr[0]]=1;
	for(int i=1;i<n;i++)
	{
		vector<int> curr(k+1,0);
		curr[0]=1;
		for(int j=1;j<=k;j++)
		{
			long long pick=0;
			if(j>=arr[i]) pick=prev[j-arr[i]]%mod;
			long long notpick=prev[j]%mod;
			curr[j]=(pick+notpick)%mod;
		}
		prev=curr;
	}
	return prev[k];
}