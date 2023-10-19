// O(nlogn) binary search best approach for finding length of lis
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    vector<int> temp;
    for(int i=0;i<nums.size();i++)
    {
        auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
        if(it==temp.end()) temp.push_back(nums[i]);
        else
        {
            int ind=it-temp.begin();
            temp[ind]=nums[i];
        }
    }
    return temp.size();
    }
};