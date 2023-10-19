//Approach 1
// class Solution{
// public:
// bool canSplit(vector<int>& nums, int i, int j, int sum, int m, vector<vector<int>>& dp, int n)
// {
//     if(i==j) return true;
//     if(sum<m) return false;
//     if(j-i+1==2) return true;
//     if(dp[i][j]!=-1) return dp[i][j];
//     return dp[i][j]=canSplit(nums,i+1,j,sum-nums[i],m,dp,n) || canSplit(nums,i,j-1,sum-nums[j],m,dp,n);
// }
// bool canSplitArray(vector<int>& nums, int m){
//     int sum=accumulate(nums.begin(),nums.end(),0);
//     int i=0;
//     int n=nums.size();
//     if(n==2) return true;
//     int j=n-1;
//     vector<vector<int>> dp(n,vector<int>(n,-1));
//     return canSplit(nums,i,j,sum,m,dp,n);
// }
// };
//Approach 2 which is better
// if there is an adjacent pair of elements with sum>=m then we will always have true
class Solution{
public:
bool canSplitArray(vector<int>& nums, int m){
  int n=nums.size();
  if(n==1 || n==2) return true;
  for(int i=0;i<n-1;i++)
  {
      if(nums[i]+nums[i+1]>=m) return true;
  }
  return false;
}
};