// if you dont understand then refer to jitesh_gawas solution
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int maxi=0;
        int i=0;
        while(i<nums.size())
        {
            int cnt=1;
            while(i+1<nums.size() && nums[i]==nums[i+1])
            {
                i++;
                cnt++;
            }
            maxi=max(maxi,cnt);
            i++;
        }
        if(maxi<=nums.size()/2)
        {
            if(nums.size()&1) return 1;
            else return 0;
        }
        return (2*maxi-nums.size());
    }
};