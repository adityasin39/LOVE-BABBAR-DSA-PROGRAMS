//if the sum of the whole array is s then as we have to do partition such that both have equal sums then we can surely say that each partition will have s/2 sum. So if s is odd then we can directly return false;
// but if s is even then we will have to find a subset which has sum equal to s/2 and we dont need to take stress about the other subset as if there exists a subset with sum equal to s/2 then the other subset will also be s/2 hence the question boils down to subset sum equal to target s/2
// using recursion
// class Solution {
// public:
//     bool solve(int index, int target, vector<int>& nums)
//     {
//         if(target==0) return true;
//         if(index==0) return nums[index]==target;
//         bool pick=false;
//         if(target>=nums[index]) pick=solve(index-1,target-nums[index],nums);
//         bool notpick=solve(index-1,target,nums);
//         return pick || notpick;
//     }
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int totalSum=0;
//         for(auto it: nums) totalSum+=it;
//         if(totalSum&1==1) return false;
//         int target=totalSum/2;
//         return solve(n-1,target,nums); 
//     }
// };
// using memoization
// class Solution {
// public:
//     bool solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp)
//     {
//         if(target==0) return true;
//         if(index==0) return nums[index]==target;
//         if(dp[index][target]!=-1) return dp[index][target];
//         bool pick=false;
//         if(target>=nums[index]) pick=solve(index-1,target-nums[index],nums,dp);
//         bool notpick=solve(index-1,target,nums,dp);
//         return dp[index][target]= pick || notpick;
//     }
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int totalSum=0;
//         for(auto it: nums) totalSum+=it;
//         if(totalSum&1==1) return false;
//         int target=totalSum/2;
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         return solve(n-1,target,nums,dp); 
//     }
// };
// using tabulation
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int totalSum=0;
//         for(auto it: nums) totalSum+=it;
//         if((totalSum&1)==1) return false;
//         int target=totalSum/2;
//         vector<vector<bool>> dp(n,vector<bool>(target+1,false));
//         for(int i=0;i<n;i++) dp[i][0]=true;
//         for(int i=0;i<=target;i++)
//         {
//             if(nums[0]==i) dp[0][i]=true;
//         }
//         for(int i=1;i<n;i++)
//         {
//             for(int j=1;j<=target;j++)
//             {
//               bool pick=false;
//               if(j>=nums[i]) pick=dp[i-1][j-nums[i]];
//               bool notpick=dp[i-1][j];
//               dp[i][j]= pick || notpick;
//             }
//         }
//         return dp[n-1][target];
//     }
// };
// space optimization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(auto it: nums) totalSum+=it;
        if((totalSum&1)==1) return false;
        int target=totalSum/2;
        vector<bool> prev(target+1,false);
        prev[0]=true;
        for(int i=0;i<=target;i++)
        {
            if(nums[0]==i) prev[i]=true;
        }
        for(int i=1;i<n;i++)
        {
            vector<bool> curr(target+1,false);
            curr[0]=true;
            for(int j=1;j<=target;j++)
            {
              bool pick=false;
              if(j>=nums[i]) pick=prev[j-nums[i]];
              bool notpick=prev[j];
              curr[j]= pick || notpick;
            }
            prev=curr;
        }
        return prev[target];
    }
};