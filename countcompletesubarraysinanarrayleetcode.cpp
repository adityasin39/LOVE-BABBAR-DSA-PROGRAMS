// optimal solution
// agar jaha j hai waha par distinct 0 hogaya toh uske aage bhi distinct 0 hi hoga isliye ans+=n-j
// sliding window technique
// O(n)
// if you dont understand then refer to https://www.youtube.com/watch?v=ZkULt4IGAuQ&t=2s
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
     int distinct=0;
     unordered_set<int> st(nums.begin(),nums.end());
     distinct=st.size();
     unordered_map<int,int> count;
     int i=0;
     int n=nums.size();
     int ans=0;
     for(int j=0;j<n;j++)
     {
        if(count[nums[j]]==0)
        {
            distinct--;
        }
        count[nums[j]]++;
        while(distinct==0)
        {
          ans+=n-j;
          count[nums[i]]--;
          if(count[nums[i]]==0) distinct++;
          i++;
        }
     }
     return ans;
    }
};
// brute force
// class Solution {
// public:
//     int countCompleteSubarrays(vector<int>& nums) {
//      int distinct=0;
//      unordered_set<int> st(nums.begin(),nums.end());
//      distinct=st.size();
//      int cnt=0;
//      for(int i=0;i<nums.size();i++)
//      {
//          unordered_set<int> st2;
//          for(int j=i;j<nums.size();j++)
//          {
//              st2.insert(nums[j]);
//              if(st2.size()==distinct) cnt++;
//          }
//      }
//         return cnt;
//     }
// };