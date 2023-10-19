// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(int i=0;i<nums.size();i++) mp[nums[i]]++;
//         int cnt=0;
//         for(auto it: mp)
//         {
//             int freq=it.second;
//             cnt+=((freq)*(freq-1))/2;
//         }
//         return cnt;   
//     }
// };
// this one is better as it is one pass
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]!=0) cnt+=mp[nums[i]];
            mp[nums[i]]++;
        }  
        return cnt;
    }
};