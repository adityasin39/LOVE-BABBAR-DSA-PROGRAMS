class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int monotone=0;
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i-1] || nums[i]<nums[i+1])
            {
                if(monotone==0) monotone=1;
                if(monotone==-1) return false;
            }
            if(nums[i]<nums[i-1] || nums[i]>nums[i+1])
            {
                if(monotone==0) monotone=-1;
                if(monotone==1) return false;
            }
        }
        return true;
    }
};