 class Solution {
 public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            if(sum<target)
            {
                while(i<j && nums[i]==nums[i+1])
                {
                    i++;
                }
                i++;
            }
            else if(sum>target)
            {
                while(i<j && nums[j]==nums[j-1])
                {
                    j--;
                }
                j--;
            }
            else
            {
                 ans.push_back(i);
                 ans.push_back(j);
            }
            
        }
        return ans;
    }
};
