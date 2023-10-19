// memoization
// class Solution {
// public:
//     int solve(int n, vector<int>& dp)
//     {
//         if(n==1 || n==2) return n;
//         if(dp[n]!=-1) return dp[n];
//         return dp[n]=solve(n-1,dp)+solve(n-2,dp);
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1,-1);
//         return solve(n,dp);
//     }
// };
// tabulation
// class Solution {
// public:
//     int climbStairs(int n) {
//     vector<int> dp(n+1,-1);
//     if(n==1 || n==2) return n; // this line is important because if n=1 then if this line is not there then the answer will get returned at the end but before that it will dp[2] ie. 2nd index which will go out of bound.
//     dp[1]=1;
//     dp[2]=2;
//     for(int i=3;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
//     }
// };
//space optimization
class Solution {
public:
    int climbStairs(int n) {
    int prev1=2;
    int prev2=1;
    if(n==1 || n==2) return n;
    for(int i=3;i<=n;i++)
    {
        int curr=0;
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
    }
};