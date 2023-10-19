//"aab", "c*a*b" this case will give true because c* means 0 or more c not c and 0 or more c
// using recursion
// class Solution {
// public:
//     bool solve(int m, int n, string& s, string& p)
//     {
//         if(m==0 && n==0) return true;
//         if(n==0) return false;
//         if(m==0) 
//         {
//             int starcount=0;
//             int nonstarcount=0;
//             for(int i=1;i<=n;i++)
//             {
//                 if(p[i-1]!='*') nonstarcount++;
//                 else starcount++;
//             }
//             return starcount==nonstarcount;
//         }
//         if(s[m-1]==p[n-1] || p[n-1]=='.') return solve(m-1,n-1,s,p);
//         if(p[n-1]=='*')
//         {
//             if(s[m-1]!=p[n-2] && p[n-2]!='.') return solve(m,n-2,s,p);
//             else return solve(m,n-2,s,p)  || solve(m,n-1,s,p) || solve(m-1,n,s,p);
//         }
//         return false;
//     }
//     bool isMatch(string s, string p) {
//      int m=s.size();
//      int n=p.size();
//      return solve(m,n,s,p);   
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
//             int starcount=0;
//             int nonstarcount=0;
//             for(int i=1;i<=n;i++)
//             {
//                 if(p[i-1]!='*') nonstarcount++;
//                 else starcount++;
//             }
//             return starcount==nonstarcount;
//         }
//         if(dp[m][n]!=-1) return dp[m][n];
//         if(s[m-1]==p[n-1] || p[n-1]=='.') return dp[m][n]= solve(m-1,n-1,s,p,dp);
//         if(p[n-1]=='*')
//         {
//             if(s[m-1]!=p[n-2] && p[n-2]!='.') return dp[m][n]= solve(m,n-2,s,p,dp);
//             else return dp[m][n]= solve(m,n-2,s,p,dp)  || solve(m,n-1,s,p,dp) || solve(m-1,n,s,p,dp);
//         }
//         return dp[m][n]= false;
//     }
//     bool isMatch(string s, string p) {
//      int m=s.size();
//      int n=p.size();
//      vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//      return solve(m,n,s,p,dp);   
//     }
// };
// using tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
     int m=s.size();
     int n=p.size();
     vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
     for(int i=1;i<=n;i++) 
     {
         int starcount=0;
         int nonstarcount=0;
            for(int j=1;j<=i;j++)
            {
                if(p[j-1]!='*') nonstarcount++;
                else starcount++;
            }
            if(starcount==nonstarcount) dp[0][i]=true;
     }
     dp[0][0]=true;
     for(int i=1;i<=m;i++)
     {
         for(int j=1;j<=n;j++)
         {
              if(s[i-1]==p[j-1] || p[j-1]=='.')  dp[i][j]= dp[i-1][j-1];
       else if(p[j-1]=='*')
        {
            if(s[i-1]!=p[j-2] && p[j-2]!='.')  dp[i][j]= dp[i][j-2];
            else  dp[i][j]= dp[i][j-2] || dp[i][j-1] || dp[i-1][j];
        }
        else dp[i][j]= false;
         }
     }   
     return dp[m][n];
     
    }
};