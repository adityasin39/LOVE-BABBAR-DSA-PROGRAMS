// if you dont understand then refer to this video https://www.youtube.com/watch?v=0FxhjY5To8M
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> freq(32,0);
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int power=log(nums[i])/log(2);
            freq[power]++;
        }
        if(sum<target) return -1;
        int minIndex=32;
        int ans=0;
        for(int i=0;i<31;i++)
        {
            int bit=1<<i;
            if(bit&target)
            {
                if(freq[i]>0)
                {
                  freq[i]--;
                }
                else
                {
                  minIndex=min(minIndex,i);
                }
            }
            if(freq[i]>0 && minIndex!=32)
            {
                freq[i]--;
                ans+=i-minIndex;
                minIndex=32;
            }
            freq[i+1]+=freq[i]/2;
        }
        return ans;
    }
};