class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> cnt(n,1);
        vector<int> lis(n,1);
        int lis_len=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(1+lis[j]>lis[i])
                    {
                        lis[i]=1+lis[j];
                        cnt[i]=cnt[j];
                    }
                    else if(1+lis[j]==lis[i])
                    {
                         cnt[i]+=cnt[j];
                    }
                }
            }
            lis_len=max(lis_len,lis[i]);
        }
       for(int i=0;i<n;i++)
       {
           if(lis[i]==lis_len) {
               count+=cnt[i];
           }
       }
       return count;
    }
};