// using recursion
// 1e9 liya hai naki INT_MAX to avoid overflow
// class Solution {
// public:
//     int solve(int n, vector<int>& coins, int amount)
//     {
//         if(amount==0) return 0;
//         if(n==0)
//         {
//             if(amount%coins[0]==0) return amount/coins[0];
//             else return 1e9;
//         }
//         int pick=1e9;
//         if(amount>=coins[n]) pick=1+solve(n,coins,amount-coins[n]);
//         int notpick=solve(n-1,coins,amount);
//         return min(pick,notpick);
// }
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         if(amount==0) return 0;
//         int ans=solve(n-1,coins,amount);
//         if(ans==1e9) return -1;
//         return ans;      
//     }
// };
// using memoization
// class Solution {
// public:
//     int solve(int n, vector<int>& coins, int amount, vector<vector<int>>& dp)
//     {
//         if(amount==0) return 0;
//         if(n==0)
//         {
//             if(amount%coins[0]==0) return amount/coins[0];
//             else return 1e9;
//         }
//         if(dp[n][amount]!=-1) return dp[n][amount];
//         int pick=1e9;
//         if(amount>=coins[n]) pick=1+solve(n,coins,amount-coins[n],dp);
//         int notpick=solve(n-1,coins,amount,dp);
//         return dp[n][amount]= min(pick,notpick);
// }
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         if(amount==0) return 0;
//         int ans=solve(n-1,coins,amount,dp);
//         if(ans==1e9) return -1;
//         return ans;      
//     }
// };
// using tabulation
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount==0) return 0;
//         int n=coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         for(int i=0;i<n;i++) dp[i][0]=0;
//         for(int i=0;i<=amount;i++) dp[0][i]=1e9;
//         for(int i=0;i<=amount;i++)
//         {
//             if(i%coins[0]==0) dp[0][i]=i/coins[0];
//         }
//         for(int i=1;i<n;i++)
//         {
//             for(int j=1;j<=amount;j++)
//             {
//                 int pick=1e9;
//                 if(j>=coins[i]) pick=1+dp[i][j-coins[i]];
//                 int notpick=dp[i-1][j];
//                 dp[i][j]=min(pick,notpick);
//             }
//         }
//         if(dp[n-1][amount]==1e9) return -1;
//         return dp[n-1][amount];
//     }
// };
// using space optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();
        vector<int> prev(amount+1,0);
        for(int i=0;i<=amount;i++) prev[i]=1e9;
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0) prev[i]=i/coins[0];
        }
        for(int i=1;i<n;i++)
        {
            vector<int> curr(amount+1,0);
            for(int j=1;j<=amount;j++)
            {
                int pick=1e9;
                if(j>=coins[i]) pick=1+curr[j-coins[i]];
                int notpick=prev[j];
                curr[j]=min(pick,notpick);
            }
            prev=curr;
        }
        if(prev[amount]==1e9) return -1;
        return prev[amount];
    }
};