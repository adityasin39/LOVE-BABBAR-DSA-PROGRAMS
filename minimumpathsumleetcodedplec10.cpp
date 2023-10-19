// using recursion
// class Solution {
// public:
//     int minimizePathSum(int row, int col,vector<vector<int>>& grid)
//     {
//         if(row==0 && col==0) return grid[row][col];
//         int up=INT_MAX;
//         int left=INT_MAX;
//         if(row-1>=0)
//         {
//              up=grid[row][col]+minimizePathSum(row-1,col,grid);
//         }
//         if(col-1>=0)
//         {
//             left=grid[row][col]+minimizePathSum(row,col-1,grid);
//         }
//         return  min(up,left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         return minimizePathSum(m-1,n-1,grid);
//     }
// };
// using memoization
// class Solution {
// public:
//     int minimizePathSum(int row, int col,vector<vector<int>>& grid, vector<vector<int>>& dp)
//     {
//         if(row==0 && col==0) return grid[row][col];
//         if(dp[row][col]!=-1) return dp[row][col];
//         int up=INT_MAX;
//         int left=INT_MAX;
//         if(row-1>=0)
//         {
//              up=grid[row][col]+minimizePathSum(row-1,col,grid,dp);
//         }
//         if(col-1>=0)
//         {
//             left=grid[row][col]+minimizePathSum(row,col-1,grid,dp);
//         }
//         return dp[row][col]= min(up,left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return minimizePathSum(m-1,n-1,grid,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         dp[0][0]=grid[0][0];
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                  if(i==0 && j==0) continue;
//                  int up=INT_MAX;
//                  int left=INT_MAX;
//                  if(i-1>=0) up=grid[i][j]+dp[i-1][j];
//                  if(j-1>=0) left=grid[i][j]+dp[i][j-1];
//                  dp[i][j]=min(up,left);
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };
// using space optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> prevRow(n,0);
        for(int i=0;i<m;i++)
        {
             vector<int> curr(n,0);
            for(int j=0;j<n;j++)
            {
                 if(i==0 && j==0) 
                 {
                     curr[j]=grid[i][j];
                     continue;
                 }
                 int up=INT_MAX;
                 int left=INT_MAX;
                 if(i-1>=0) up=grid[i][j]+prevRow[j];
                 if(j-1>=0) left=grid[i][j]+curr[j-1];
                 curr[j]=min(up,left);
            }
            prevRow=curr;
        }
        return prevRow[n-1];
    }
};