// class Solution {
// public:
//     int solve(int n, int amount, vector<int>& coins,  vector<vector<int>>& dp)
//     {
//        if(amount==0) return 1;
//        if(n==0)
//        {
//            if(amount%coins[0]==0) return 1;
//            else return 0;
//        }
//        if(dp[n][amount]!=-1) return dp[n][amount];
//        int pick=0;
//        if(amount>=coins[n]) pick=solve(n,amount-coins[n],coins,dp);
//        int notpick=solve(n-1,amount,coins,dp);
//        return dp[n][amount]=pick+notpick;
//     }
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         return solve(n-1,amount,coins,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         for(int i=0;i<n;i++) dp[i][0]=1;
//         for(int i=0;i<=amount;i++) dp[0][i]=0;
//         for(int i=0;i<=amount;i++)
//         {
//             if(i%coins[0]==0) dp[0][i]=1;
//         }
//         for(int i=1;i<n;i++)
//         {
//             for(int j=1;j<=amount;j++)
//             {
//                 int pick=0;
//                 if(j>=coins[i]) pick=dp[i][j-coins[i]];
//                 int notpick=dp[i-1][j];
//                 dp[i][j]=pick+notpick;
//             }
//         }
//         return dp[n-1][amount];
//     }
// };
// using space optimization
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         vector<int> prev(amount+1,0);
//         prev[0]=1;
//         for(int i=0;i<=amount;i++)
//         {
//             if(i%coins[0]==0) prev[i]=1;
//         }
//         for(int i=1;i<n;i++)
//         {
//             vector<int> curr(amount+1,0);
//             curr[0]=1;
//             for(int j=1;j<=amount;j++)
//             {
//                 int pick=0;
//                 if(j>=coins[i]) pick=curr[j-coins[i]];
//                 int notpick=prev[j];
//                 curr[j]=pick+notpick;
//             }
//             prev=curr;
//         }
//         return prev[amount];
//     }
// };