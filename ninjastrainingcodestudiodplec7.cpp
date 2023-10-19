// my version of recursion but follow the below approaches only.
// #include<bits/stdc++.h>
// void solve(int n, vector<vector<int>> &points,int row, int col, int sum,
//  int& prevsum)
//  {
//      if(row>n-1)
//      {
//          prevsum=max(sum,prevsum);
//          return;
//      }
//      sum+=points[row][col];
//      if(col!=0) solve(n,points,row+1,0,sum,prevsum);
//      if(col!=1) solve(n,points,row+1,1,sum,prevsum);
//      if(col!=2) solve(n,points,row+1,2,sum,prevsum);
//  }
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<int> dp
//     int sum=0;
//     int prevsum=INT_MIN;
//     int row=0;
//     for(int col=0;col<3;col++)
//     solve(n,points,row,col,sum,prevsum);
//     return prevsum;
// }
// using recursion
// #include<bits/stdc++.h>
// int solve(int n, vector<vector<int>> &points, int last)
// {
//     if(n<0) return 0;
//     int maxi=0;
//     for(int i=0;i<=2;i++)
//     {
//         if(last!=i)
//         {
//            int path=solve(n-1,points,i) + points[n][i];
//            maxi=max(maxi,path);
//         }
//     }
//     return maxi;
// }
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//       int last=3;
//      return solve(n-1,points,last);
// }
// using memoization
// #include<bits/stdc++.h>
// int solve(int n, vector<vector<int>> &points, int last, vector<vector<int>>& dp)
// {
//     if(n<0) return 0;
//     if(dp[n][last]!=-1) return dp[n][last];
//     int maxi=0;
//     for(int i=0;i<=2;i++)
//     {
//         if(last!=i)
//         {
//            int path=solve(n-1,points,i,dp) + points[n][i];
//            maxi=max(maxi,path);
//         }
//     }
//     return dp[n][last]= maxi;
// }
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n,vector<int>(4,-1));
//       int last=3;
//      return solve(n-1,points,last,dp);
// }
// using tabulation
// #include<bits/stdc++.h>
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//  vector<vector<int>> dp(n,vector<int>(3,-1));
//  dp[0][0]=points[0][0];
//  dp[0][1]=points[0][1];
//  dp[0][2]=points[0][2];
//  for(int i=1;i<n;i++)
//  {
//      dp[i][0]=max(dp[i-1][1],dp[i-1][2])+points[i][0];
//      dp[i][1]=max(dp[i-1][0],dp[i-1][2])+points[i][1];
//      dp[i][2]=max(dp[i-1][0],dp[i-1][1])+points[i][2];
//  }
//  int ans=0;
//  ans=max(ans,dp[n-1][0]);
//  ans=max(ans,dp[n-1][1]);
//  ans=max(ans,dp[n-1][2]);
//  return ans;  
// }
// using space optimization SC=O(4) and TC=O(n)
#include<bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points)
{
  vector<int> prev(3,-1);
  prev[0]=points[0][0];
  prev[1]=points[0][1];
  prev[2]=points[0][2];
  for(int i=1;i<n;i++)
  {
      vector<int> curr(3,-1);
      curr[0]=max(prev[1],prev[2])+points[i][0];
      curr[1]=max(prev[0],prev[2])+points[i][1];
      curr[2]=max(prev[0],prev[1])+points[i][2];
      prev=curr;
  } 
  int ans=0;
  ans=max(ans,prev[0]);
  ans=max(ans,prev[1]);
  ans=max(ans,prev[2]);
  return ans;
}
