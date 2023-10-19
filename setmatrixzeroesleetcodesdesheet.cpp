// in this we need to store the row nos and col nos in the matrix itself
// we cant set 0 on the fly while iterating because if we encounter a 0 afterwards which we previously made 0 then there will be wrong answer
// we will store the row and col nos in the first row and first col so that we can easily check for the remaining matrix;
//for the overlapping cell, we use two variables instead
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroCol=false;
        bool isZeroRow=false;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]==0)
            {
                isZeroRow=true;
                break;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                isZeroCol=true;
                break;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        if(isZeroRow)
        {
            for(int i=0;i<n;i++) matrix[0][i]=0;
        }
        if(isZeroCol)
        {
            for(int i=0;i<m;i++) matrix[i][0]=0;
        }
    }
};