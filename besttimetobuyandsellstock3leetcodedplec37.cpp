// read the following solutions but after reading them go to striver notes of this lec to learn about the second technique
// using recursion
// class Solution{
// public:
//     int solve(int n, vector<int>& prices, int buy, int& length, int cap)
//     {
//         if(n==length) return 0;
//         if(cap==0) return 0;
//         if(buy==1)
//         {
//             return max(-prices[n]+solve(n+1,prices,0,length,cap), solve(n+1,prices,1,length,cap));
//         }
//         else return max(prices[n]+solve(n+1,prices,1,length,cap-1), solve(n+1,prices,0,length,cap));
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         return solve(0,prices,1,n,2);
//     }
// };
// using memoization
// class Solution{
// public:
//     int solve(int n, vector<int>& prices, int buy, int& length, int cap, vector<vector<vector<int>>>& dp)
//     {
//         if(n==length) return 0;
//         if(cap==0) return 0;
//         if(dp[n][buy][cap]!=-1) return dp[n][buy][cap];
//         if(buy==1)
//         {
//             return dp[n][buy][cap]=max(-prices[n]+solve(n+1,prices,0,length,cap,dp), solve(n+1,prices,1,length,cap,dp));
//         }
//         else return dp[n][buy][cap]=max(prices[n]+solve(n+1,prices,1,length,cap-1,dp), solve(n+1,prices,0,length,cap,dp));
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
//         return solve(0,prices,1,n,2,dp);
//     }
// };
// har ek loop ko recursion ke opposite mein chalana hai in tabulation
// using tabulation
// class Solution{
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
//         for(int i=0;i<2;i++)
//         {
//             for(int j=0;j<3;j++)
//             {
//                 dp[n][i][j]=0; // agar -1 ki jagah 0 lenge initially toh yeh dono base case likhne ki zaroorat nahi
//             }
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<2;j++)
//             {
//                 dp[i][j][0]=0;
//             }
//         }
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int j=0;j<2;j++)
//             {
//                 for(int k=1;k<3;k++){
//                 if(j==1)
//                 {
//                     dp[i][j][k]=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
//                 }
//                 else dp[i][j][k]=max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
//                 }
//             }
//         }
//         return dp[0][1][2];      
//     }
// };
// using space optimization
class Solution{
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> prev(2,vector<int>(3,0));
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                prev[i][j]=0; 
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            vector<vector<int>> curr(2,vector<int>(3,0));
            for(int j=0;j<2;j++)
            {
                for(int k=1;k<3;k++){
                if(j==1)
                {
                    curr[j][k]=max(-prices[i]+prev[0][k],prev[1][k]);
                }
                else curr[j][k]=max(prices[i]+prev[1][k-1],prev[0][k]);
                }
            }
            prev=curr;
        }
        return prev[1][2];      
    }
};