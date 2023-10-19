// dp[i][j] represent edge length of the biggest square whose lower right corner element is matrix[i][j]. Also there are dp[i][j] squares whose lower right corner element are matrix[i][j]. The answer of count-square-submatrices-with-all-ones is sum of all dp[i][j].

// As Figure, the square edge length ( whose lower right corner element is matrix[i][j] ) is not greater than the minimum of three arrows + 1.

// Fortunately it can be equal to when matrix[i][j]==1. On this condition dp[i][j]=the minimum of three arrows + 1;

// And when matrix[i][j]==0 , dp[i][j]=0.

// So
// if matrix[i][j]==1 : 
//     if i!=0 and j!=0: 
//         dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1
//     else: 
//         dp[i][j] = 0 + 1
// else:
//     dp[i][j] = 0
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        int cnt=0;
        for(int i=0;i<n;i++){ 
        dp[0][i]=matrix[0][i];
        cnt+=matrix[0][i];
        }
        for(int i=1;i<m;i++) {
            dp[i][0]=matrix[i][0];
            cnt+=matrix[i][0];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                   dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                else dp[i][j]=0;
                cnt+=dp[i][j];
            }
        }
        return cnt;
    }
};