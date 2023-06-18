class Solution {
public:
//Best approach TC=O(3n)=O(n) for first for loop and then O(2n) for another for loop and while loop combined. SC=O(n) 
// this is a lot better than brute force as we are moving forward only when we find that the elment is the least consecutive.
 int longestConsecutive(vector<int>& nums) {
     int n=nums.size();
     if(n==0) return 0;
     int ans=1;
     unordered_set<int> st;
     for(int i=0;i<n;i++) st.insert(nums[i]);//O(1)
     for(auto it:st)
     {
         if(st.find(it-1)==st.end())
         {
             int x=it;
             int cnt=1;
             while(st.find(x+1)!=st.end())
             {
                 cnt++;
                 x=x+1;
             }
             ans=max(cnt,ans);
         }
     }
     return ans;
// Brute force TC=O(n^2) as if the array is like 1,2,3,4,5 then we will have to check the whole array for every element. SC=O(1)
// bool isPresent(vector<int>& nums, int element, int n)
// {
//     for(int i=0;i<n;i++)
//     {
//      if(element==nums[i]) return true;
//     }
//     return false;
// }
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();
//         if(n==0) return 0;
//         int ans=1;
//         for(int i=0;i<n;i++)
//         {
//             int cnt=1;
//          while(isPresent(nums,nums[i]+1,n))
//          {
//              cnt++;
//          }
//          ans=max(cnt,ans);
//         }
//         return ans;
// better approach TC=O(nlogn) and SC=O(1)
    //       int n=nums.size();
    //       if(n==0) return 0;
    // sort(nums.begin(),nums.end());  
    // int cnt=1;
    // int ans=1;
    // for(int i=1;i<n;i++)
    // {
    //     if(nums[i]==nums[i-1]+1)
    //     {
    //           cnt++;
    //           ans=max(ans,cnt);
    //     }
    //     else if(nums[i]==nums[i-1]) continue;
    //    else cnt=1;
    // }
    // return ans;
    }
};