// this is same as partition with a given difference
// intution: as we have to put + before some numbers and - before other numbers, that means the numbers having + can be considered a partition and the numbers having - as the other and the target acts as the difference
class Solution {
	long long mod=1e9+7;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totSum=accumulate(nums.begin(),nums.end(),0);
	if((totSum-target)&1 || totSum-target<0) return 0;
	int sum2=(totSum-target)/2;
	vector<vector<int>> dp(n,vector<int>(sum2+1,0));
	if(nums[0]==0) dp[0][0]=2;
    if(nums[0]!=0) dp[0][0]=1;
	if(nums[0]!=0 && nums[0]<=sum2) dp[0][nums[0]]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=sum2;j++) // 0 se start hoga because there is no base case for 0
		{
			long long pick=0;
			if(j>=nums[i]) pick=dp[i-1][j-nums[i]]%mod;
			long long notpick=dp[i-1][j]%mod;
			dp[i][j]=(pick+notpick)%mod;
		}
	}
	return dp[n-1][sum2];
    }
};