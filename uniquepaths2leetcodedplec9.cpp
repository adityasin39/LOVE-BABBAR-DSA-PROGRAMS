// using recursion
// class Solution {
// public:
//     int solve(int row, int col, vector<vector<int>>& obstacleGrid)
//     {
//         if(row<0 || col<0) return 0;
//         if(obstacleGrid[row][col]==1) return 0; // agar iss line ko row<0 || col<0 wali line ke upar daal diya toh error aayega
//         if(row==0 && col==0) return 1;
//         return solve(row-1,col,obstacleGrid)+solve(row,col-1,obstacleGrid);
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         if(obstacleGrid[0][0]==1) return 0;
//         return solve(m-1,n-1,obstacleGrid);
//     }
// };
// using memoization
// class Solution {
// public:
//     int solve(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
//     {
//         if(row<0 || col<0) return 0;
//         if(obstacleGrid[row][col]==1) return 0; // agar iss line ko row<0 || col<0 wali line ke upar daal diya toh error aayega
//         if(row==0 && col==0) return 1;
//         if(dp[row][col]!=-1) return dp[row][col];
//         return dp[row][col]=solve(row-1,col,obstacleGrid,dp)+solve(row,col-1,obstacleGrid,dp);
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         if(obstacleGrid[0][0]==1) return 0;
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return solve(m-1,n-1,obstacleGrid,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//       if(obstacleGrid[0][0]==1) return 0;
//       int m=obstacleGrid.size();
//       int n=obstacleGrid[0].size();
//       if(obstacleGrid[m-1][n-1]==1) return 0;
//       vector<vector<int>> dp(m,vector<int>(n,-1));
//       dp[0][0]=1;
//       for(int i=0;i<m;i++)
//       {
//           for(int j=0;j<n;j++)
//           {
//               if(i==0 && j==0) continue;
//               int up=0;
//               if(i-1>=0 && obstacleGrid[i-1][j]==0) up=dp[i-1][j];
//               int left=0;
//               if(j-1>=0 && obstacleGrid[i][j-1]==0) left=dp[i][j-1];
//               dp[i][j]=up+left;
//           }
//       }
//         return dp[m-1][n-1];
//     }
// };
// using space optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      if(obstacleGrid[0][0]==1) return 0;
      int m=obstacleGrid.size();
      int n=obstacleGrid[0].size();
      if(obstacleGrid[m-1][n-1]==1) return 0;
      vector<int> prev(n,0);
      for(int i=0;i<m;i++)
      {
          vector<int> curr(n,0);
          for(int j=0;j<n;j++)
          {
              if(i==0 && j==0)
              {
                  curr[j]=1;
                  continue;
              }
              int up=0;
              if(i-1>=0 && obstacleGrid[i-1][j]==0) up=prev[j];
              int left=0;
              if(j-1>=0 && obstacleGrid[i][j-1]==0) left=curr[j-1];
              curr[j]=up+left;
          }
          prev=curr;
      }
        return prev[n-1];
    }
};