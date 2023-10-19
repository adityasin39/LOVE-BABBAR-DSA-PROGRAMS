// using recursion
// class Solution {
// public:
//     int solve(int n, int row, int col, vector<vector<int>>& triangle)
//     {
//         if(row==n-1) return triangle[row][col];
//         int firstpath=triangle[row][col]+solve(n,row+1,col,triangle);
//         int secondpath=triangle[row][col]+solve(n,row+1,col+1,triangle);
//         return min(firstpath,secondpath);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         return solve(n,0,0,triangle);
//     }
// };
// using memoization
// class Solution {
// public:
//     int solve(int n, int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp)
//     {
//         if(row==n-1) return triangle[row][col];
//         if(dp[row][col]!=-1) return dp[row][col];
//         int firstpath=triangle[row][col]+solve(n,row+1,col,triangle,dp);
//         int secondpath=triangle[row][col]+solve(n,row+1,col+1,triangle,dp);
//         return dp[row][col]=min(firstpath,secondpath);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         return solve(n,0,0,triangle,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//        int n=triangle.size();
//        vector<vector<int>> dp(n,vector<int>(n,0));
//        for(int i=0;i<n;i++) dp[n-1][i]=triangle[n-1][i];
//        for(int i=n-2;i>=0;i--)
//        {
//            for(int j=i;j>=0;j--)
//            {
//                int firstpath=triangle[i][j]+dp[i+1][j];
//                int secondpath=triangle[i][j]+dp[i+1][j+1];
//                dp[i][j]=min(firstpath,secondpath);
//            }
//        }
//        return dp[0][0];
//     }
// };
// space optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       vector<int> next(n,0);
       for(int i=0;i<n;i++) next[i]=triangle[n-1][i];
       for(int i=n-2;i>=0;i--)
       {
           vector<int> curr(i+1,0);
           for(int j=i;j>=0;j--)
           {
               int firstpath=triangle[i][j]+next[j];
               int secondpath=triangle[i][j]+next[j+1];
               curr[j]=min(firstpath,secondpath);
           }
           next=curr;
       }
       return next[0];
    }
};