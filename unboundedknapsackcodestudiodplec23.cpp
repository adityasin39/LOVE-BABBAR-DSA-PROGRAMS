// using recursion
// #include <bits/stdc++.h> 
// int solve(int idx, int w, vector<int>& profit, vector<int>& weight)
// {
//     if(w==0) return 0;
//     if(idx<0) return 0;
//     int pick=INT_MIN;
//     if(w>=weight[idx]) pick=profit[idx]+solve(idx,w-weight[idx],profit,weight);
//     int notpick=solve(idx-1,w,profit,weight);
//     return max(pick,notpick);
// }
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     return solve(n-1,w,profit,weight);
// }
// using memoization
// #include <bits/stdc++.h> 
// int solve(int idx, int w, vector<int>& profit, vector<int>& weight, vector<vector<int>>& dp)
// {
//     if(w==0) return 0;
//     if(idx<0) return 0;
//     if(dp[idx][w]!=-1) return dp[idx][w];
//     int pick=INT_MIN;
//     if(w>=weight[idx]) pick=profit[idx]+solve(idx,w-weight[idx],profit,weight,dp);
//     int notpick=solve(idx-1,w,profit,weight,dp);
//     return dp[idx][w]=max(pick,notpick);
// }
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     vector<vector<int>> dp(n,vector<int>(w+1,-1));
//     return solve(n-1,w,profit,weight,dp);
// }
// using tabulation and index shifting
// #include <bits/stdc++.h> 
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     vector<vector<int>> dp(n+1,vector<int>(w+1,0));
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=w;j++)
//         {
//             int pick=INT_MIN;
//             if(j>=weight[i-1]) pick=profit[i-1]+dp[i][j-weight[i-1]];
//             int notpick=dp[i-1][j];
//             dp[i][j]=max(pick,notpick);
//         }
//     }
//     return dp[n][w];
// }
// space optimization to 1-d array
#include <bits/stdc++.h> 
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            int pick=INT_MIN;
            if(j>=weight[i-1]) pick=profit[i-1]+prev[j-weight[i-1]];
            int notpick=prev[j];
            prev[j]=max(pick,notpick);
        }
    }
    return prev[w];
}