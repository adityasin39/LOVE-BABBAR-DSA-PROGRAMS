class Solution {
public:
    void lis(vector<int>& nums, int n, vector<int>& dp)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                if(1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                }
            }
        }
    }
}
int longestBitonicSequence(vector<int>& arr, int n) {
	  vector<int> dpIncrease(n,1);
	  vector<int> dpDecrease(n,1);
	  lis(arr,n,dpIncrease);
	  reverse(arr.begin(),arr.end());
	  lis(arr,n,dpDecrease);
	  int ans=0;
	  for(int i=0;i<n;i++)
	  {
          if(dpIncrease[i]>1 && dpDecrease[n-1-i]>1) // this is important because we need a mountain array, thus we cant have only increasing or a decreasing subsequence
		  ans=max(ans,dpIncrease[i]+dpDecrease[n-1-i]-1);
	  }
	  return ans;
} 
    int minimumMountainRemovals(vector<int>& nums) {
      return (nums.size()-longestBitonicSequence(nums,nums.size()));      
    }
};