#include <bits/stdc++.h> 
// int solve(vector<int>& arr, int N, int i, int j)
// {
//     if(i==j) return 0;
//     int mini=INT_MAX;
//     for(int k=i;k<j;k++)
//     {
//         int steps=arr[i-1]*arr[k]*arr[j]+solve(arr,N,i,k)+solve(arr,N,k+1,j);
//         mini=min(mini,steps);
//     }
//     return mini;
// }
// int matrixMultiplication(vector<int> &arr, int N)
// {
//    int i=1;
//    int j=N-1;
//    return solve(arr,N,i,j);
// }
// int solve(vector<int>& arr, int N, int i, int j, vector<vector<int>>& dp)
// {
//     if(i==j) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int mini=INT_MAX;
//     for(int k=i;k<j;k++)
//     {
//         int steps=arr[i-1]*arr[k]*arr[j]+solve(arr,N,i,k,dp)+solve(arr,N,k+1,j,dp);
//         mini=min(mini,steps);
//     }
//     return dp[i][j]=mini;
// }
// int matrixMultiplication(vector<int> &arr, int N)
// {
//    int i=1;
//    int j=N-1;
//    vector<vector<int>> dp(N,vector<int>(N,-1));
//    return solve(arr,N,i,j,dp);
// }
int matrixMultiplication(vector<int> &arr, int N)
{
   vector<vector<int>> dp(N,vector<int>(N,-1));
   for(int i=1;i<N;i++) dp[i][i]=0;
   for(int i=N-1;i>=1;i--)
   {
       for(int j=i+1;j<N;j++) //as j is always to the right of i so j=i+1 is better
       {
           if(i==j) continue;
           int mini=INT_MAX;
           for(int k=i;k<j;k++)
           {
               int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
               mini=min(mini,steps);
           }
           dp[i][j]=mini;
       }
   }
   return dp[1][N-1];
}