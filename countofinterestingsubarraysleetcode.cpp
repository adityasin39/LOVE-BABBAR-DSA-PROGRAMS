// if you dont understand then refer to the first solution on leetcode
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%modulo==k) nums[i]=1;
            else nums[i]=0;
        }
        unordered_map<int,int> freq;
        freq[0]=1;
        long long ans=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int curremainder=sum%modulo;
            int prefixremainder=curremainder-k;
            if(prefixremainder<0) prefixremainder+=modulo; 
            if(freq.count(prefixremainder)) ans+=freq[prefixremainder];
            freq[curremainder]++;
        }
        return ans;
    }
};