// using recursion
// #include <bits/stdc++.h> 
// int solve(vector<int> weight, vector<int> value, int n, int bagWeight)
// {
// 	if(bagWeight==0) return 0;
// 	if(n==0)
// 	{
// 		if(weight[0]<=bagWeight) return value[0];
// 		else return 0;
// 	} 
// 	int pick=INT_MIN;
// 	if(weight[n]<=bagWeight) pick=value[n]+solve(weight,value,n-1,bagWeight-weight[n]);
// 	int notpick=solve(weight,value,n-1,bagWeight);
// 	return max(pick,notpick);
// }
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	return solve(weight,value,n-1,maxWeight);
// }
// using memoization
// #include <bits/stdc++.h> 
// int solve(vector<int> weight, vector<int> value, int n, int bagWeight, vector<vector<int>>& dp)
// {
// 	if(bagWeight==0) return 0;
// 	if(n==0)
// 	{
// 		if(weight[0]<=bagWeight) return value[0];
// 		else return 0;
// 	} 
// 	if(dp[n][bagWeight]!=-1) return dp[n][bagWeight];
// 	int pick=INT_MIN;
// 	if(weight[n]<=bagWeight) pick=value[n]+solve(weight,value,n-1,bagWeight-weight[n],dp);
// 	int notpick=solve(weight,value,n-1,bagWeight,dp);
// 	return dp[n][bagWeight]=max(pick,notpick);
// }
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
// 	return solve(weight,value,n-1,maxWeight,dp);
// }
// using tabulation
// #include <bits/stdc++.h> 
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
// 	for(int i=0;i<n;i++) dp[i][0]=0;
// 	for(int i=0;i<=maxWeight;i++) dp[0][i]=0;
//     for(int i=weight[0];i<=maxWeight;i++) dp[0][i]=value[0];
// 	for(int i=1;i<n;i++)
// 	{
// 		for(int j=1;j<=maxWeight;j++)
// 		{
// 			int pick=INT_MIN;
// 			if(weight[i]<=j) pick=value[i]+dp[i-1][j-weight[i]];
// 			int notpick=dp[i-1][j];
// 			dp[i][j]=max(pick,notpick);
// 		}
// 	}
// 	return dp[n-1][maxWeight];
// }
// using space optimization
// #include <bits/stdc++.h> 
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	vector<int> prev(maxWeight+1,0);
//     for(int i=weight[0];i<=maxWeight;i++) prev[i]=value[0];
// 	for(int i=1;i<n;i++)
// 	{
// 		vector<int> curr(maxWeight+1,0);
// 		for(int j=1;j<=maxWeight;j++)
// 		{
// 			int pick=INT_MIN;
// 			if(weight[i]<=j) pick=value[i]+prev[j-weight[i]];
// 			int notpick=prev[j];
// 			curr[j]=max(pick,notpick);
// 		}
// 		prev=curr;
// 	}
// 	return prev[maxWeight];
// }
// using single array space optimization
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0);
    for(int i=weight[0];i<=maxWeight;i++) prev[i]=value[0];
	for(int i=1;i<n;i++)
	{
		for(int j=maxWeight;j>=1;j--)
		{
			int pick=INT_MIN;
			if(weight[i]<=j) pick=value[i]+prev[j-weight[i]];
			int notpick=prev[j];
			prev[j]=max(pick,notpick);
		}
	}
	return prev[maxWeight];
}