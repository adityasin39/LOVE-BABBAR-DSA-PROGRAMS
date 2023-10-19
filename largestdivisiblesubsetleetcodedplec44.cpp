//after thinking a bit, you will realize that this is similar to lis.
// we just need to sort it to avoid complications and instead of nums[n]>nums[greater_index] in lis, we need to have nums[n]%nums[prev]==0 and then we need to have prev=n to carry forward.
// but to print the subset, we need to use the 2nd approach of lis and update the condition as stated above.
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++) hash[i]=i;
        int maxi=0;
        int lis_index=0;//should be 0 because if there is only one element then that has to be the lis because if you put -1 then the below loops wont run and the while loop would give error because of  hash[-1]
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
               if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
               {
                   dp[i]=1+dp[j];
                   hash[i]=j;
               }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lis_index=i;
            }
        }
        int i=lis_index;
        vector<int> ans;
        while(hash[i]!=i)
        {
           ans.push_back(nums[i]);
           i=hash[i];
        }
        ans.push_back(nums[i]);
        return ans;

    }
};