// TC is O(log(m*n))
// same as binary search for 1-d array but the only difference is that we need to map the correct index in the 2-d array after treating this as sorted row wise 1-d array that is
// 1 3 5 7 10 11 16 20 23 30 34 60 
// s                             e
// s=0 e=rows*cols-1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int start=0;
        int end=rows*cols-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int element=matrix[mid/cols][mid%cols]; // to get row do mid/cols and for col do mid%cols
            if(element==target) return true;
            else if(element<target) start=mid+1;
            else end=mid-1;
        }
        return false;
    }
};