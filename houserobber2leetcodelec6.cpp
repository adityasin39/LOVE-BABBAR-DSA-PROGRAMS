// Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem has degenerated to the House Robber, which is already been solved.
// using recursion
// class Solution {
// public:
// int solve(int n,vector<int>& nums,int end)
// {
//     if(n<end) return 0;
//     if(n==end) return nums[end]; // agar ek hi element toh include karenge hi max sum ke liye.
//     int pick=solve(n-2,nums,end)+nums[n];
//     int notpick=solve(n-1,nums,end);
//     return max(pick,notpick);
// }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return nums[0];
//         int excludefirst=solve(n-2,nums,0);
//         int excludelast=solve(n-1,nums,1);
//         return max(excludefirst,excludelast);
//     }
// };
// using memoization
// class Solution {
// public:
// int solve(int n, vector<int>& nums, int end, vector<int>& dp) {
//     if (n < end) return 0;
//     if (n == end) return nums[end];
//     if (dp[n] != -1) return dp[n];
//     int pick = solve(n - 2, nums, end, dp) + nums[n];
//     int notpick = solve(n - 1, nums, end, dp);
//     return dp[n] = max(pick, notpick);
// }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,-1);
//         if(n==1) return nums[0];
//         int excludefirst=solve(n-2,nums,0,dp);
//         for(int i=0;i<n;i++) dp[i]=-1;
//         int excludelast=solve(n-1,nums,1,dp);
//         return max(excludefirst,excludelast);
//     }
// };
// using tabulation
// class Solution {
// public:
//  int tabulation(vector<int>& nums,int start, int end)
//  {
//       vector<int> dp(end-start+1,-1);
//       dp[0]=nums[start];
//       dp[1]=max(nums[start],nums[start+1]);
//       for(int i=2;i<=end-start;i++)
//       {
//           int pick=dp[i-2]+nums[start+i];
//           int notpick=dp[i-1];
//           dp[i]=max(pick,notpick);
//       }
//       return dp[end-start];
//  }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return nums[0];
//         if(n==2) return max(nums[0],nums[1]);
//         int excludefirst=tabulation(nums,0,n-2);
//         int excludelast=tabulation(nums,1,n-1);
//         return max(excludefirst,excludelast);
//     }
// };
// using space optimization
class Solution {
public:
 int tabulation(vector<int>& nums,int start, int end)
 {
   
      int prev2=nums[start];
      int prev1=max(nums[start],nums[start+1]);
      for(int i=2;i<=end-start;i++)
      {
          int pick=prev2+nums[start+i];
          int notpick=prev1;
          int curr=max(pick,notpick);
          prev2=prev1;
          prev1=curr;
      }
      return prev1;
 }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int excludefirst=tabulation(nums,0,n-2);
        int excludelast=tabulation(nums,1,n-1);
        return max(excludefirst,excludelast);
    }
};