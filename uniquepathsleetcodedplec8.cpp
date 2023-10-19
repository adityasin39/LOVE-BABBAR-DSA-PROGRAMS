// using recursion
// class Solution {
// public:
//     int countPaths(int row, int col)
//     {
//         if(row<0 || col<0) return 0;
//         if(row==0 && col==0) return 1;
//         int up=countPaths(row-1,col);
//         int left=countPaths(row,col-1);
//         return up+left;
//     }
//     int uniquePaths(int m, int n) {
//         int row=m-1;
//         int col=n-1;
//         return countPaths(row,col);
//     }
// };
// using memoization
// class Solution {
// public:
//     int countPaths(int row, int col,vector<vector<int>>& dp )
//     {
//         if(row<0 || col<0) return 0;
//         if(row==0 && col==0) return 1;
//         if(dp[row][col]!=-1) return dp[row][col];
//         int up=countPaths(row-1,col,dp);
//         int left=countPaths(row,col-1,dp);
//         return dp[row][col]=up+left;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         int row=m-1;
//         int col=n-1;
//         return countPaths(row,col,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         dp[0][0]=1;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                if(i==0 && j==0) continue;
//                int up=-1;
//                int left=-1;
//                if(i-1<0)  up=0;
//                else  up=dp[i-1][j];
//                if(j-1<0) left=0;
//                else left=dp[i][j-1];
//                dp[i][j]=up+left;
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };
// using space optimization
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> prevRow(n,0);
//         int leftCell=1;
//         for(int i=0;i<m;i++)
//         {
//             vector<int> curr(n,0);
//             for(int j=0;j<n;j++)
//             {
//                if(i==0 && j==0) curr[j]=1;
//                int  up=prevRow[j];
//                int  left=leftCell;
//                curr[j]=up+left;
//                leftCell=curr[j];
//             }
//             prevRow=curr;
//             leftCell=0;
//         }
//         return prevRow[n-1];
//     }
// };
// using permutation and combination. This is the best solution
class Solution {
public:
// to reach the bottom right cell we need to take m-1 down steps and n-1 right steps always in any order so we have to place m-1 and n-1 in a total of m-1+n-1 steps so we get m+n-2 C m-1(NCr) or m+n-2 C n-1. We can do whichever takes less time so we take min of(m,n). 
    long long uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = min(m, n) - 1;
        long long paths = 1;
        for (int i = 1; i <= r; i++) {
            paths *= (N - r + i);
            paths /= i;
        }
        return paths;
    }
};
