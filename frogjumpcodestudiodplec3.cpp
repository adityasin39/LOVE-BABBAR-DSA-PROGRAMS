// my version of recursion but always follow the below approaches.
// #include <bits/stdc++.h>
// void solve(int step, int energy, vector<int>& heights, int size, int prevHeight, int& prevenergy)
// {
//     if(step>size) return;
//     if(step==size)
//     {
//         energy+=abs(heights[step-1]-prevHeight);
//         energy=min(energy,prevenergy);
//         prevenergy=energy;
//         return;
//     }
//     energy+=abs(heights[step-1]-prevHeight);
//     solve(step+1,energy,heights,size,heights[step-1],prevenergy);
//     solve(step+2,energy,heights,size,heights[step-1],prevenergy);
// } 
// int frogJump(int n, vector<int> &heights)
// {
//     int energy=0;
//     int prevenergy=INT_MAX;
//     solve(1,energy,heights,n,heights[0],prevenergy);
//     return prevenergy;
// }    
// whenever we need to try all possible paths to find the answer, we use recursion
// using normal recursion
// #include <bits/stdc++.h> 
// int solve(int n, vector<int>& heights)
// {
//     if(n==0) return 0; // energy required from 0 to 0th stair.
//     int left=solve(n-1,heights)+abs(heights[n]-heights[n-1]);
//     int right=INT_MAX;
//     if(n-2>=0)
//     right=solve(n-2,heights)+abs(heights[n]-heights[n-2]);
//     return min(left,right);
// }
// int frogJump(int n, vector<int> &heights)
// {
//    return solve(n-1,heights);
// }
// using memoization
// #include <bits/stdc++.h> 
// int solve(int n, vector<int>& heights,vector<int>& dp)
// {
//     if(n==0) return 0;
//     if(dp[n]!=-1) return dp[n];
//     int left=solve(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
//     int right=INT_MAX;
//     if(n-2>=0)
//     right=solve(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
//     return dp[n]=min(left,right);
// }
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n,-1);
//    return solve(n-1,heights,dp);
// }
// using tabulation
// #include <bits/stdc++.h> 
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n,-1);
//     dp[0]=0;
//     for(int i=1;i<n;i++)
//     {
//         int left=dp[i-1]+abs(heights[i]-heights[i-1]);
//         int right=INT_MAX;
//         if(i-2>=0)
//         right=dp[i-2]+abs(heights[i]-heights[i-2]);
//         dp[i]=min(left,right);
//     }
//     return dp[n-1];
// }
// using space optimization
// TC=O(n) and SC=O(1)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int prev2=0;
    int prev1=0;
    for(int i=1;i<n;i++)
    {
        int left=prev1+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i-2>=0)
        right=prev2+abs(heights[i]-heights[i-2]);
        int cur=min(left,right);
         prev2=prev1;
        prev1=cur;
    }
    return prev1;
}