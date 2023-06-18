 class Solution {
 public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Approach 1 using unordered map
        // unordered map insertion/deletion/search takes amortized O(1) time and in worst of the worst cases takes O(n) time whereas map takes O(logn)
        // So here TC=O(n) and in case of map it would be O(nlogn)
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
             ans.push_back(i);
             ans.push_back(mp[target-nums[i]]);
            }
            mp[nums[i]]=i;
        }
        return  ans;
        //Approach 2
        // sort(nums.begin(),nums.end());
        // vector<int> ans;
        // int i=0;
        // int j=nums.size()-1;
        // while(i<j)
        // {
        //     int sum=nums[i]+nums[j];
        //     if(sum<target)
        //     {
        //         while(i<j && nums[i]==nums[i+1])
        //         {
        //             i++;
        //         }
        //         i++;
        //     }
        //     else if(sum>target)
        //     {
        //         while(i<j && nums[j]==nums[j-1])
        //         {
        //             j--;
        //         }
        //         j--;
        //     }
        //     else
        //     {
        //          ans.push_back(i);
        //          ans.push_back(j);
        //     }
            
        // }
        // return ans;
    }
};
