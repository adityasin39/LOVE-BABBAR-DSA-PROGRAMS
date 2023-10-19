class Solution {
    // the trick is to find lis and then subtract
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<=nums[i])
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return nums.size()-maxi;
    }
};