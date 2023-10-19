class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int res=nums[0];
        for(int i=1;i<nums.size();i++) res=(res&nums[i]);
        if(res!=0) return 1;
        int cnt=0;
        int j=0;
        int val=nums[j];
        while(j<nums.size())
        {
            if(val==0)
            {
                if(j+1<nums.size()) val=nums[j+1];
                cnt++;
            }
            j++;
            if(j<nums.size()) val=(val&nums[j]);
        }
        return cnt;
    }
};