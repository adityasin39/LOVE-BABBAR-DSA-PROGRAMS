// This although seems like a basic dp problem, can't be solve by it due to the constraints.

// The trick here is to think in reverse. We need a subarray of maximum length whose sum is TotalSum - x. As we remove minimum no of elements from left and right to get a sum of x, we will be left with a subarray of maximum length having sum of TotalSum-x.

// So, now it's a sliding window problem, Cheers!
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left=0;
        int right=0;
        int sum=0;
        sum+=nums[right];
        int total=accumulate(nums.begin(),nums.end(),0);
        int reqSum=total-x;
        if(reqSum<0) return -1;
        if(reqSum==0) return nums.size();
        int ans=0;
        while(right<nums.size())
        {
            while(sum>reqSum)
            {
                sum-=nums[left];
                left++;
            }
            if(sum==reqSum) ans=max(ans,right-left+1);
            right++;
            if(right<nums.size()) sum+=nums[right];
        }
        if(ans==0) return -1;
        return (nums.size()-ans);
    }
};