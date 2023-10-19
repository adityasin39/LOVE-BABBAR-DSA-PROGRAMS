// if you dont understand then refer to striver lec notes or neetcode video
// using recursion
// class Solution {
// public:
//     int solve(int i, int j, vector<int>& nums)
//     {
//         if(i>j) return 0;
//         int maxi=INT_MIN;
//         for(int k=i;k<=j;k++)
//         {
//              int coins=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums)+solve(k+1,j,nums);
//              maxi=max(coins,maxi);
//         }
//         return maxi;
//     }
//     int maxCoins(vector<int>& nums) {
//          int n=nums.size();
//         nums.push_back(1);
//         nums.insert(nums.begin(),1);
//         return solve(1,n,nums);
//     }
// };
// using memoization
// class Solution {
// public:
//     int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
//     {
//         if(i>j) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int maxi=INT_MIN;
//         for(int k=i;k<=j;k++)
//         {
//              int coins=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
//              maxi=max(coins,maxi);
//         }
//         return dp[i][j]=maxi;
//     }
//     int maxCoins(vector<int>& nums) {
//          int n=nums.size();
//         nums.push_back(1);
//         nums.insert(nums.begin(),1);
//         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//         return solve(1,n,nums,dp);
//     }
// };
// using tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
         int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--)
        {
            for(int j=i;j<=n;j++) // because j will always be >=i
            {
                int maxi=INT_MIN;
               for(int k=i;k<=j;k++)
               {
                  int coins=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]; // dp[k+1][j] will give runtime error when k==n so declare n+2 size matrix
                  maxi=max(maxi,coins);
               }
               dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};