// there is an optimization where you will have O(1) space
class Solution {
public:
    bool solve(vector<int>& nums, int i, int n, vector<int>& dp)
    {
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        bool twoConsecutive=false;
        if(n-i>=2 && nums[i]==nums[i+1])
        {
           twoConsecutive=solve(nums,i+2,n,dp);
        }
        bool threeConsecutive=false;
        if(n-i>=3 && nums[i]==nums[i+1] && nums[i+1]==nums[i+2])
        {
            threeConsecutive=solve(nums,i+3,n,dp);
        }
        bool threeIncreasing=false;
        if(n-i>=3 && nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2])
        {
            threeIncreasing=solve(nums,i+3,n,dp);
        }
        return dp[i]=twoConsecutive || threeConsecutive || threeIncreasing;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,0,n,dp);
    }
};