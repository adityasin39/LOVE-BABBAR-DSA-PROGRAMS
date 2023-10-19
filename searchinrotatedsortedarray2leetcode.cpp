// if you dont understand then refer to striver video of this question
// for e.g. [3,1,3,3,3,3,3] the time complexity will be O(n) coz we are doing start++ and end-- a lot of times here
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[start] && nums[mid]==nums[end])
            {
                start++;
                end--;
                continue;
            }
            // if left part is sorted
            if(nums[mid]>=nums[start])
            {
                if(target<=nums[mid] && target>=nums[start]) end=mid-1;
                else start=mid+1;
            }
            // if right part is sorted
            else
            {
                if(target<=nums[end] && target>=nums[mid]) start=mid+1;
                else end=mid-1;
            }
        }
        return false;
    }
};