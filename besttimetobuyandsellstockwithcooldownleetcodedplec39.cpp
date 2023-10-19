// using recursion
// class Solution {
// public:
//     int solve(int n, int buy, int length, vector<int>& prices)
//     {
//         if(n>length-1) return 0;
//         if(buy==1)
//         {
//             return max(-prices[n]+solve(n+1,0,length,prices),solve(n+1,1,length,prices));
//         }
//         else return max(prices[n]+solve(n+2,1,length,prices),solve(n+1,0,length,prices));
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         return solve(0,1,n,prices);
//     }
// };
// using memoization
// class Solution {
// public:
//     int solve(int n, int buy, int length, vector<int>& prices, vector<vector<int>>& dp)
//     {
//         if(n>length-1) return 0;
//         if(dp[n][buy]!=-1) return dp[n][buy];
//         if(buy==1)
//         {
//             return dp[n][buy]=max(-prices[n]+solve(n+1,0,length,prices,dp),solve(n+1,1,length,prices,dp));
//         }
//         else return dp[n][buy]=max(prices[n]+solve(n+2,1,length,prices,dp),solve(n+1,0,length,prices,dp));
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return solve(0,1,n,prices,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>> dp(n+2,vector<int>(2,-1));
//         for(int i=0;i<2;i++)
//         {
//             dp[n][i]=0;
//             dp[n+1][i]=0;
//         }
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int j=0;j<2;j++)
//             {
//                 if(j==1) dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
//                 else dp[i][j]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
//             }
//         }
//       return dp[0][1];      
//     }
// };
// time as well as space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> prev1(2,0);
        vector<int> prev2(2,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(2,0);
           curr[1]=max(-prices[i]+prev1[0],prev1[1]);
           curr[0]=max(prices[i]+prev2[1],prev1[0]);
           prev2=prev1;
           prev1=curr;
        }
      return prev1[1];      
    }
};