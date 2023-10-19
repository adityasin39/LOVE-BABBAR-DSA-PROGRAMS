//using recursion
// #include <bits/stdc++.h> 
// bool solve(int n, int k, vector<int>& arr)
// {
//     if(k==0) return true;
//     if(n==0) return arr[0]==k;
//     bool pick=false;
//     if(k>=arr[n])
//     pick=solve(n-1,k-arr[n],arr);
//     bool notpick=solve(n-1,k,arr);
//     return pick||notpick;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     return solve(n-1,k,arr);
// }
// using memoization
// #include <bits/stdc++.h> 
// bool solve(int n, int k, vector<int>& arr, vector<vector<int>>& dp)
// {
//     if(k==0) return true;
//     if(n==0) return arr[0]==k;
//     if(dp[n][k]!=-1) return dp[n][k];
//     bool pick=false;
//     if(k>=arr[n])
//     pick=solve(n-1,k-arr[n],arr,dp);
//     bool notpick=solve(n-1,k,arr,dp);
//     return dp[n][k]=pick||notpick;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<int>> dp(n,vector<int>(k+1,-1));
//     return solve(n-1,k,arr,dp);
// }
// using tabulation
// #include <bits/stdc++.h> 
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<bool>> dp(n,vector<bool>(k+1,false));
//     for(int i=0;i<n;i++) dp[i][0]=true;
//     if(arr[0]<=k) dp[0][arr[0]]=true;
//     for(int i=1;i<n;i++)
//     {
//         for(int j=1;j<=k;j++)
//         {
//             bool pick=false;
//             if(j>=arr[i]) pick=dp[i-1][j-arr[i]];
//             bool notpick=dp[i-1][j];
//             dp[i][j]=pick||notpick;
//         }
//     }
//     return dp[n-1][k];
// }
// using space optimization
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,false);
    prev[0]=true;
    if(arr[0]<=k) prev[arr[0]]=true;
    for(int i=1;i<n;i++)
    {
        vector<bool> curr(k+1,false);
        curr[0]=true;
        for(int j=1;j<=k;j++)
        {
            bool pick=false;
            if(j>=arr[i]) pick=prev[j-arr[i]];
            bool notpick=prev[j];
            curr[j]=pick||notpick;
        }
        prev=curr;
    }
    return prev[k];
}