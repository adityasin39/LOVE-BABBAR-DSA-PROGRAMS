// copy pasted from best time to buy and sell stock 3
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n=prices.size();
//         int m=k;
//         vector<vector<int>> prev(2,vector<int>(k+1,0));
//         for(int i=0;i<2;i++)
//         {
//             for(int j=0;j<k+1;j++)
//             {
//                 prev[i][j]=0; 
//             }
//         }
//         for(int i=n-1;i>=0;i--)
//         {
//             vector<vector<int>> curr(2,vector<int>(k+1,0));
//             for(int j=0;j<2;j++)
//             {
//                 for(int k=1;k<m+1;k++){
//                 if(j==1)
//                 {
//                     curr[j][k]=max(-prices[i]+prev[0][k],prev[1][k]);
//                 }
//                 else curr[j][k]=max(prices[i]+prev[1][k-1],prev[0][k]);
//                 }
//             }
//             prev=curr;
//         }
//         return prev[1][k];         
//     }
// };
// using recursion
// using the other approach of best time to buy and sell stock 3
// class Solution {
// public:
//     int solve(int k, vector<int>& prices, int length, int n, int transactions)
//     {
//         if(n==length || transactions==2*k) return 0;
//         if(transactions%2==0)
//         {
//             return max(-prices[n] + solve(k,prices,length,n+1,transactions+1),solve(k,prices,length,n+1,transactions));
//         }
//         else return max(prices[n]+solve(k,prices,length,n+1,transactions+1),solve(k,prices,length,n+1,transactions));
//     }
//     int maxProfit(int k, vector<int>& prices) {
//       int n=prices.size();
//       int transactions=0;
//       return solve(k,prices,n,0,transactions);      
//     }
// };
// using memoization
// class Solution {
// public:
//     int solve(int k, vector<int>& prices, int length, int n, int transactions, vector<vector<int>>& dp)
//     {
//         if(n==length || transactions==2*k) return 0;
//         if(dp[n][transactions]!=-1)  return dp[n][transactions];
//                 if(transactions%2==0)
//         {
//             return dp[n][transactions]=max(-prices[n] + solve(k,prices,length,n+1,transactions+1,dp),solve(k,prices,length,n+1,transactions,dp));
//         }
//         else return dp[n][transactions]=max(prices[n]+solve(k,prices,length,n+1,transactions+1,dp),solve(k,prices,length,n+1,transactions,dp));
//     }
//     int maxProfit(int k, vector<int>& prices) {
//       int n=prices.size();
//       vector<vector<int>> dp(n,vector<int>(2*k,-1));
//       int transactions=0;
//       return solve(k,prices,n,0,transactions,dp);      
//     }
// };
// using tabulation
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//       int n=prices.size();
//       vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
//       for(int i=0;i<=2*k;i++) dp[n][i]=0;
//       for(int i=0;i<=n;i++) dp[i][2*k]=0;
//       for(int i=n-1;i>=0;i--)
//       {
//           for(int j=2*k-1;j>=0;j--)
//           {
//               if(j%2==0) dp[i][j]=max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
//               else dp[i][j]=max(prices[i]+dp[i+1][j+1],dp[i+1][j]);
//           }
//       }
//       return dp[0][0];
//     }
// };
// using space optimization
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
      int n=prices.size();
     vector<int> prev(2*k+1,0);
      for(int i=n-1;i>=0;i--)
      {
          vector<int> curr(2*k+1,0);
          for(int j=2*k-1;j>=0;j--)
          {
              if(j%2==0) curr[j]=max(-prices[i]+prev[j+1],prev[j]);
              else curr[j]=max(prices[i]+prev[j+1],prev[j]);
          }
          prev=curr;
      }
      return prev[0];
    }
};