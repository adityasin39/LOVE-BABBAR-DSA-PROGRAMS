// by recursion
//class Solution {
// public:
//     int solve(int n, vector<int>& prices, int buy, int& length)
//     {
//         if(n==length) return 0;
//         if(buy==1)
//         {
//             return max(-prices[n]+solve(n+1,prices,0,length), solve(n+1,prices,1,length));
//         }
//         else return max(prices[n]+solve(n+1,prices,1,length), solve(n+1,prices,0,length));
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         return solve(0,prices,1,n);
//     }
// };
// using memoization
// class Solution{
// public:
//     int solve(int n, vector<int>& prices, int buy, int& length,vector<vector<int>>& dp)
//     {
//         if(n==length) return 0;
//         if(dp[n][buy]!=-1) return dp[n][buy];
//         if(buy==1)
//         {
//             return dp[n][buy]=max(-prices[n]+solve(n+1,prices,0,length,dp), solve(n+1,prices,1,length,dp));
//         }
//         else return dp[n][buy]= max(prices[n]+solve(n+1,prices,1,length,dp), solve(n+1,prices,0,length,dp));
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return solve(0,prices,1,n,dp);
//     }
// };
// using tabulation
// class Solution{
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>> dp(n+1,vector<int>(2,-1));
//         for(int i=0;i<2;i++) dp[n][i]=0;
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int j=0;j<2;j++) // tabulation mein recursion se ulta loop chalate hain
//             {
//                 if(j==1)
//                 {
//                     dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
//                 }
//                 else dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
//             }
//         }
//         return dp[0][1];
        
//     }
// };
// after reading the below space optimization solution, go to striver notes of this lec to check the 4 variable space optimization
// using space optimization
class Solution{
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> prev(2,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(2,0);
            for(int j=0;j<2;j++)
            {
                if(j==1)
                {
                    curr[j]=max(-prices[i]+prev[0],prev[1]);
                }
                else curr[j]=max(prices[i]+prev[1],prev[0]);
            }
            prev=curr;
        }
        return prev[1];
    }
};