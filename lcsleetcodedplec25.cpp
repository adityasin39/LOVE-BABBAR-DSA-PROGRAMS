// in order to avoid negative index of the base case in tabulation, we do shifting of indexes 
// using recursion
// class Solution {
// public:
// // strings ko by reference hi bhejenge to avoid tle
//     int solve(int m, int n, string& text1, string& text2)
//     {
//        if(m==0 || n==0) return 0;
//        if(text1[m-1]==text2[n-1]) return 1+solve(m-1,n-1,text1,text2);
//        else return max(solve(m-1,n,text1,text2),solve(m,n-1,text1,text2));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size();
//         int n=text2.size();
//         return solve(m,n,text1,text2);
//     }
// };
// using memoization
// class Solution {
// public:
// // strings ko by reference hi bhejenge to avoid tle
//     int solve(int m, int n, string& text1, string& text2, vector<vector<int>>& dp)
//     {
//        if(m==0 || n==0) return 0;
//        if(dp[m][n]!=-1) return dp[m][n];
//        if(text1[m-1]==text2[n-1]) return dp[m][n]=1+solve(m-1,n-1,text1,text2,dp);
//        else return dp[m][n]=max(solve(m-1,n,text1,text2,dp),solve(m,n-1,text1,text2,dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size();
//         int n=text2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         return solve(m,n,text1,text2,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size();
//         int n=text2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         for(int i=0;i<=n;i++) dp[0][i]=0;
//         for(int i=0;i<=m;i++) dp[i][0]=0;
//         for(int i=1;i<=m;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
//                 else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp[m][n];
//     }
// };
// using space optimization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<int> prev(n+1,0);
        for(int i=1;i<=m;i++)
        {
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n];
    }
};