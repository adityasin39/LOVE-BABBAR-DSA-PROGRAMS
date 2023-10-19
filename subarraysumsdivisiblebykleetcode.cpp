// if you dont understand then refer to subarraysumequalsk question and https://www.youtube.com/watch?v=QM0klnvTQzk
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> freq;
        int sum=0;
        freq[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int remainder=sum%k;
            if(remainder<0) remainder+=k;
            if(freq.count(remainder)) ans+=freq[remainder];
            freq[remainder]++;
        }
        return ans;
    }
};