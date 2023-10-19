//using recursion
//there will never be an out of bound case when you move upwards
// class Solution {
// public:
//     int pathSum(int row, int col, vector<vector<int>>& matrix, int n )
//     {
//           if(row==0) return matrix[row][col];
//           int diagonalLeft=INT_MAX;
//           int diagonalRight=INT_MAX;
//           int up=matrix[row][col]+pathSum(row-1,col,matrix,n);
//           if(col-1>=0) diagonalLeft=matrix[row][col]+pathSum(row-1,col-1,matrix,n);
//           if(col+1<n) diagonalRight=matrix[row][col]+pathSum(row-1,col+1,matrix,n);
//           int sum=INT_MAX;
//           sum=min(sum,up);
//           sum=min(sum,diagonalLeft);
//           sum=min(sum,diagonalRight);
//           return sum;
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int mini=INT_MAX;
//         for(int i=0;i<n;i++)
//         {
//            mini=min(mini,pathSum(n-1,i,matrix,n));
//         }
//         return mini;
//     }
// };
// using memoization
// although memoization and tabulation have same time complexity then too memoization gives tle because it recursion overhead takes time too.
// class Solution {
// public:
//     int pathSum(int row, int col, vector<vector<int>>& matrix, int n , vector<vector<int>>& dp)
//     {
//           if(row==0) return matrix[row][col];
//           if(dp[row][col]!=-1) return dp[row][col];
//           int diagonalLeft=INT_MAX;
//           int diagonalRight=INT_MAX;
//           int up=matrix[row][col]+pathSum(row-1,col,matrix,n,dp);
//           if(col-1>=0) diagonalLeft=matrix[row][col]+pathSum(row-1,col-1,matrix,n,dp);
//           if(col+1<n) diagonalRight=matrix[row][col]+pathSum(row-1,col+1,matrix,n,dp);
//           int sum=INT_MAX;
//           sum=min(sum,up);
//           sum=min(sum,diagonalLeft);
//           sum=min(sum,diagonalRight);
//           return dp[row][col]= sum;
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         int mini=INT_MAX;
//         for(int i=0;i<n;i++)
//         {
//            mini=min(mini,pathSum(n-1,i,matrix,n,dp));
//         }
//         return mini;
//     }
// };
// using tabulation
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         for(int i=0;i<n;i++)
//         {
//             dp[0][i]=matrix[0][i];
//         }
//         for(int j=1;j<n;j++)
//         {
//             for(int k=0;k<n;k++)
//             {
//                 int diagonalLeft=INT_MAX;
//                 int diagonalRight=INT_MAX;
//                int up=matrix[j][k]+dp[j-1][k];
//                if(k-1>=0) diagonalLeft=matrix[j][k]+dp[j-1][k-1];
//                if(k+1<n) diagonalRight=matrix[j][k]+dp[j-1][k+1];
//                int ans=INT_MAX;
//                ans=min(ans,up);
//                ans=min(ans,diagonalLeft);
//                ans=min(ans,diagonalRight);
//                dp[j][k]=ans;
//             }
//         }
//         int finalAns=INT_MAX;
//         for(int i=0;i<n;i++)
//         {
//             finalAns=min(finalAns,dp[n-1][i]);
//         }
//         return finalAns;      
//     }
// };
// using space optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prevRow(n,0);
        for(int i=0;i<n;i++)
        {
            prevRow[i]=matrix[0][i];
        }
        for(int j=1;j<n;j++)
        {
            vector<int> curr(n,0);
            for(int k=0;k<n;k++)
            {
                int diagonalLeft=INT_MAX;
                int diagonalRight=INT_MAX;
               int up=matrix[j][k]+prevRow[k];
               if(k-1>=0) diagonalLeft=matrix[j][k]+prevRow[k-1];
               if(k+1<n) diagonalRight=matrix[j][k]+prevRow[k+1];
               int ans=INT_MAX;
               ans=min(ans,up);
               ans=min(ans,diagonalLeft);
               ans=min(ans,diagonalRight);
               curr[k]=ans;
            }
            prevRow=curr;
        }
        int finalAns=INT_MAX;
        for(int i=0;i<n;i++)
        {
            finalAns=min(finalAns,prevRow[i]);
        }
        return finalAns;      
    }
};