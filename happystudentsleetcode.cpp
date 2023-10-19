class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        if(nums[0]>0) ans=1;
        for(int i=0;i<nums.size();i++)
        {
            if((i+1)>nums[i] && i==nums.size()-1) ans++;
            else if((i+1)>nums[i] && (i+1)<nums[i+1]) ans++;
        }
        return ans;
    }
};