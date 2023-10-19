// using recursion
// class Solution {
// public:
//     int solve(int m, int n, string& s, string& t)
//     {
//         if(n==0) return 1;
//         if(m==0) return 0;
//         if(s[m-1]==t[n-1]) return solve(m-1,n-1,s,t)+solve(m-1,n,s,t);
//         else return solve(m-1,n,s,t);
//     }
//     int numDistinct(string s, string t) {
//         int m=s.size();
//         int n=t.size();
//         return solve(m,n,s,t);
//     }
// };
// using memoization
// class Solution {
// public:
//     int solve(int m, int n, string& s, string& t, vector<vector<int>>& dp)
//     {
//         if(n==0) return 1;
//         if(m==0) return 0;
//         if(dp[m][n]!=-1) return dp[m][n];
//         if(s[m-1]==t[n-1]) return dp[m][n]=solve(m-1,n-1,s,t,dp)+solve(m-1,n,s,t,dp);
//         else return dp[m][n]=solve(m-1,n,s,t,dp);
//     }
//     int numDistinct(string s, string t) {
//         int m=s.size();
//         int n=t.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         return solve(m,n,s,t,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//         int numDistinct(string s, string t) {
//         int m=s.size();
//         int n=t.size();
//         vector<vector<long long>> dp(m+1,vector<long long>(n+1,-1));
//         for(int i=0;i<=n;i++) dp[0][i]=0;
//         for(int i=0;i<=m;i++) dp[i][0]=1;
//         for(int i=1;i<=m;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(s[i-1]==t[j-1]) dp[i][j]=int(dp[i-1][j-1]+dp[i-1][j]);// typecast kiya hai to avoid overflow
//                 else dp[i][j]=dp[i-1][j];
//             }
//         }
//         return dp[m][n];
//     }
// };
// using space optimization
// class Solution {
// public:
//         int numDistinct(string s, string t) {
//         int m=s.size();
//         int n=t.size();
//         vector<long long> prev(n+1,0);
//         prev[0]=1;
//         for(int i=1;i<=m;i++)
//         {
//             vector<long long> curr(n+1,0);
//             curr[0]=1;
//             for(int j=1;j<=n;j++)
//             {
//                 if(s[i-1]==t[j-1]) curr[j]=int(prev[j-1]+prev[j]);// typecast kiya hai to avoid overflow aur hamesha aise hi overflow ko avoid karna
//                 else curr[j]=prev[j];
//             }
//             prev=curr;
//         }
//         return prev[n];
//     }
// };
// using single array space optimization
class Solution {
public:
        int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<long long> prev(n+1,0);
        prev[0]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=n;j>=1;j--)
            {
                if(s[i-1]==t[j-1]) prev[j]=int(prev[j-1]+prev[j]);// typecast kiya hai to avoid overflow
                else prev[j]=prev[j]; // this line becomes redundant so you can remove it
            }
        }
        return prev[n];
    }
};