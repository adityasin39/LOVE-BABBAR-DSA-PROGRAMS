// using recursion
// class Solution {
// public:
// int solve(int n,vector<int>& nums)
// {
//     if(n<0) return 0;
//     if(n==0) return nums[0]; // agar ek hi element toh include karenge hi max sum ke liye.
//     int pick=solve(n-2,nums)+nums[n];
//     int notpick=solve(n-1,nums);
//     return max(pick,notpick);
// }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         return solve(n-1,nums);
//     }
// };
// using memoization
// class Solution {
// public:
// int solve(int n,vector<int>& nums, vector<int>& dp)
// {
//     if(n<0) return 0;
//     if(n==0) return nums[0];
//     if(dp[n]!=-1) return dp[n];
//      pick=solve(n-2,nums,dp)+nums[n];
//     int notpick=solve(n-1,nums,dp);
//     return dp[n]=max(pick,notpick);
// }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,-1);
//         return solve(n-1,nums,dp);
//     }
// };
// using tabulation
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//     int n=nums.size();
//     if(n==1) return nums[0];//edge case
//     vector<int> dp(n,-1);
//     dp[0]=nums[0];
//     dp[1]=max(nums[0],nums[1]); 
//     for(int i=2;i<n;i++)
//     {
//        int pick=dp[i-2]+nums[i];
//        int notpick=dp[i-1];
//        dp[i]=max(pick,notpick); 
//     }
//     return dp[n-1];
//     }
// };
// using space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];//edge case
    int prev2=nums[0];
    int prev1=max(nums[0],nums[1]);
    for(int i=2;i<n;i++)
    {
       int pick=prev2+nums[i];
       int notpick=prev1;
       int curr=max(pick,notpick); 
       prev2=prev1;
       prev1=curr;
    }
    return prev1;
    }
};