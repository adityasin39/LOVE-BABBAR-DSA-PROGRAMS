// aisa lagega ki ek normal loop lagake ho jaaega but nahi ho paaega, consider this eg. s="adceb" p="*a*b"
// using recursion
// class Solution {
// public:
//     bool solve(int m, int n, string& s, string& p)
//     {
//         if(m==0 && n==0) return true;
//         if(n==0) return false;
//         if(m==0)
//         {
//             for(int i=0;i<n;i++) 
//             {
//                 if(p[i]!='*') return false; //aisa ho sakta hai ki string p mein sirf * bache ho toh * signify 0 character so the answer will be true so checking it.
//             }
//             return true;
//         }
//         if(s[m-1]==p[n-1] || p[n-1]=='?') return solve(m-1,n-1,s,p);
//         if(p[n-1]=='*') return solve(m,n-1,s,p) || solve(m-1,n,s,p); // recursive tree banao samajh aayega
//         return false; 
//     }
//     bool isMatch(string s, string p) {
//         int m=s.size();
//         int n=p.size();
//         return solve(m,n,s,p);
//     }
// };
// using memoization
// class Solution {
// public:
//     bool solve(int m, int n, string& s, string& p, vector<vector<int>>& dp)
//     {
//         if(m==0 && n==0) return true;
//         if(n==0) return false;
//         if(m==0)
//         {
//             for(int i=0;i<n;i++) 
//             {
//                 if(p[i]!='*') return false;
//             }
//             return true;
//         }
//         if(dp[m][n]!=-1) return dp[m][n];
//         if(s[m-1]==p[n-1] || p[n-1]=='?') return dp[m][n]=solve(m-1,n-1,s,p,dp);
//         if(p[n-1]=='*') return dp[m][n]=solve(m,n-1,s,p,dp) || solve(m-1,n,s,p,dp);
//         return dp[m][n]= false; 
//     }
//     bool isMatch(string s, string p) {
//         int m=s.size();
//         int n=p.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         return solve(m,n,s,p,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int m=s.size();
//         int n=p.size();
//         vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
//         for(int i=1;i<=m;i++) dp[i][0]=false;
//         for(int i=0;i<=n;i++) dp[0][i]=true;
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(p[j]!='*') 
//                 {
//                     dp[0][i]=false;
//                     break;
//                 }
//             }
//         }
//         for(int i=1;i<=m;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
//                 else if(p[j-1]=='*') dp[i][j]=dp[i][j-1] || dp[i-1][j];
//                 else dp[i][j]=false; 
//             }
//         }
//         return dp[m][n];      
//     }
// };
// using space optimization
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<bool> prev(n+1,false);
        for(int i=0;i<=n;i++) prev[i]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(p[j]!='*') 
                {
                    prev[i]=false;
                    break;
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            vector<bool> curr(n+1,false);
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?') curr[j]=prev[j-1];
                else if(p[j-1]=='*') curr[j]=curr[j-1] || prev[j];
                else curr[j]=false; 
            }
            prev=curr;
        }
        return prev[n];      
    }
};
