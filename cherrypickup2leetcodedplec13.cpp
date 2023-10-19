// using recursion
// class Solution {
// public:
//     int solve(int row1, int col1, int row2, int col2, int m, int n, vector<vector<int>>& grid)
//     {
//         if(col1<0 || col1>=n || col2<0 || col2>=n) return -1e9;// whenever a path is not possible then return a big negative value if you want to find maximum. This is because if we return 0 and if that paths value is maximum then it can become our answer without being a valid path. If you return INT_MIN then there is chance of overflow so return -1e9 always
//         if(row1==m-1 && row2==m-1 && col1!=col2) return grid[row1][col1]+grid[row2][col2];//this edge case is very important because they can meet in the last row as well
//         if(row1==m-1 && row2==m-1 && col1==col2) return grid[row1][col1];
//         int maxi=INT_MIN;
//         for(int i=-1;i<=1;i++)
//         {
//             for(int j=-1;j<=1;j++)
//             {
//                if(row1==row2 && col1==col2) maxi=max(maxi,grid[row1][col1]+solve(row1+1,col1+i,row2+1,col2+j,m,n,grid));
//                else maxi=max(maxi,grid[row1][col1]+grid[row2][col2]+solve(row1+1,col1+i,row2+1,col2+j,m,n,grid));
//             }
//         }
//         return maxi;
//     }
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         return solve(0,0,0,n-1,m,n,grid);
//     }
// };
// Actually, you can omit i2 as both are moving simultaneously reducing it to 3-d dp
// class Solution {
// public:
//     int solve(int row, int col1, int col2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
//     {
//         if(col1<0 || col1>=n || col2<0 || col2>=n) return -1e9;
//         if(row==m-1 && col1!=col2) return grid[row][col1]+grid[row][col2];
//         if(row==m-1 && col1==col2) return grid[row][col1];
//         if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
//         int maxi=INT_MIN;
//         for(int i=-1;i<=1;i++)
//         {
//             for(int j=-1;j<=1;j++)
//             {
//                if(col1==col2) maxi=max(maxi,grid[row][col1]+solve(row+1,col1+i,col2+j,m,n,grid,dp));
//                else maxi=max(maxi,grid[row][col1]+grid[row][col2]+solve(row+1,col1+i,col2+j,m,n,grid,dp));
//             }
//         }
//         return dp[row][col1][col2]=maxi;
//     }
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
//         return solve(0,0,n-1,m,n,grid,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,0)));
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(i==j) dp[m-1][i][j]=grid[m-1][i];
//                 else dp[m-1][i][j]=grid[m-1][i]+grid[m-1][j];
//             }
//         }
//         for(int i=m-2;i>=0;i--)
//         {
//             for(int j=n-1;j>=0;j--)
//             {
//                 for(int k=0;k<n;k++)
//                 {
//                       int maxi=INT_MIN;
//                      for(int l=-1;l<=1;l++)
//                      {
//                        for(int p=-1;p<=1;p++)
//                        {
//                         if(j+l>=0 && j+l<n && k+p>=0 && k+p<n){
//                         if(j==k) maxi=max(maxi,grid[i][j]+dp[i+1][j+l][k+p]);
//                         else maxi=max(maxi,grid[i][j]+grid[i][k]+dp[i+1][j+l][k+p]);
//                         }
//                        }
//                      }
//                        dp[i][j][k]=maxi;
//                 }
//             }
//         }
//         return dp[0][0][n-1];        
//     }
// };
// using space optimization
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> next(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) next[i][j]=grid[m-1][i];
                else next[i][j]=grid[m-1][i]+grid[m-1][j];
            }
        }
        for(int i=m-2;i>=0;i--)
        {
            vector<vector<int>> curr(n,vector<int>(n,0));
            for(int j=n-1;j>=0;j--)
            {
                for(int k=0;k<n;k++)
                {
                      int maxi=INT_MIN;
                     for(int l=-1;l<=1;l++)
                     {
                       for(int p=-1;p<=1;p++)
                       {
                        if(j+l>=0 && j+l<n && k+p>=0 && k+p<n){
                        if(j==k) maxi=max(maxi,grid[i][j]+next[j+l][k+p]);
                        else maxi=max(maxi,grid[i][j]+grid[i][k]+next[j+l][k+p]);
                        }
                       }
                     }
                       curr[j][k]=maxi;
                }
            }
            next=curr;
        }
        return next[0][n-1];        
    }
};