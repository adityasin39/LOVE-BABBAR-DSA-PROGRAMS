// when the matrix is row and column wise sorted then we always start from top right and in the worst case the target would be at the bottom left so in such a case whole last column and last row would be traversed making the TC as O(m+n)
// we have to stop whenever the index goes out of bound which means we didnt find our element
// if you still dont understand then refer to https://www.youtube.com/watch?v=VS0BcOiKaGI
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        while(i>=0 && i<matrix.size() && j>=0 && j<matrix[0].size())
        {
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) i++;
            else j--;
        }
        return false;
    }
};