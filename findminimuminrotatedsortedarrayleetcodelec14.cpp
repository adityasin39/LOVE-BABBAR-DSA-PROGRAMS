//in this question, the array will always be sorted and rotated. We have to find the minimum element and in this question if we draw a graph then we get two increasing lines in which the least element of the second line will be the minimum element and the maximum element of the second line will be smaller than the least element of the first line.On finding mid, we will check on which line it lies, if it lies on the first line then it is sure from the graph that the minimum element will be after the mid. So we do start=mid+1 but if mid lies on the second line then it is confirm that the minimum will be before mid so we do end=mid-1.Now there is an edge case which is if the array is rotated nums.size() times then it comes in its original form. So to deal with this, check line no. 13.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]>=nums[0]) start=mid+1;
            else end=mid-1;
        }
        if(start==nums.size()) return nums[0];
        return nums[start];
    }
};