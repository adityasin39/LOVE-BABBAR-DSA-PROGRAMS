// if you dont understand then refer to https://www.youtube.com/watch?v=xvNwoz-ufXA
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count=0;
        int cursum=0;
        for(int i=0;i<nums.size();i++)
        {
            cursum+=nums[i];
            if(cursum==k) count++;
            if(mp.find(cursum-k)!=mp.end()) count+=mp[cursum-k];
            mp[cursum]++;
        }
        return count;
    }
};