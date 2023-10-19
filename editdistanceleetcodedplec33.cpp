// using recursion
//class Solution {
// public:
//     int solve(int m, int n, string& word1, string& word2)
//     {
//         if(m==0 && n==0) return 0;
//         if(m==0) return n; // agar pehli string hi khatam ho gayi then we will need n number of insertions to make word1 equal to word2
//         if(n==0) return m;
//         if(word1[m-1]==word2[n-1]) return solve(m-1,n-1,word1,word2);
//         return 1+ min(solve(m-1,n,word1,word2),min(solve(m,n-1,word1,word2),solve(m-1,n-1,word1,word2)));
//     }
//     int minDistance(string word1, string word2) {
//         int m=word1.size();
//         int n=word2.size();
//         return solve(m,n,word1,word2);
//     }
// };
// using memoization
// class Solution {
// public:
//     int solve(int m, int n, string& word1, string& word2, vector<vector<int>>& dp)
//     {
//         if(m==0 && n==0) return 0;
//         if(m==0) return n;
//         if(n==0) return m;
//         if(dp[m][n]!=-1) return dp[m][n];
//         if(word1[m-1]==word2[n-1]) return dp[m][n]=solve(m-1,n-1,word1,word2,dp);
//         return dp[m][n]= 1+ min(solve(m-1,n,word1,word2,dp),min(solve(m,n-1,word1,word2,dp),solve(m-1,n-1,word1,word2,dp)));
//     }
//     int minDistance(string word1, string word2) {
//         int m=word1.size();
//         int n=word2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         return solve(m,n,word1,word2,dp);
//     }
// };
// using tabulation
// class Solution{
// public:
//     int minDistance(string word1, string word2) {
//         int m=word1.size();
//         int n=word2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         for(int i=0;i<=m;i++) dp[i][0]=i;
//         for(int i=0;i<=n;i++) dp[0][i]=i;
//         for(int i=1;i<=m;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
//                 else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
//             }
//         }
//         return dp[m][n];
//     }
// };
class Solution{
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<int> prev(n+1,0);
        for(int i=0;i<=n;i++) prev[i]=i;
        for(int i=1;i<=m;i++)
        {
            vector<int> curr(n+1,0);
            curr[0]=i;
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1]) curr[j]=prev[j-1];
                else curr[j]=1+min(prev[j],min(curr[j-1],prev[j-1]));
            }
            prev=curr;
        }
        return prev[n];
    }
};