// Both approaches are 0 ms
// Approach 1.
// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         vector<int> temp(nums.size(),0);
//         int rotatecount=1;
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             if(nums[i]<=nums[i+1]) rotatecount++;
//             else break;
//         }
       // rotatecount se kitne positions se rotate kiya hai pata chal jaaega. 
//         if(rotatecount==nums.size()) return true; // in this case it is rotated 0 or nums.size() times and is sorted.
//         for(int i=0;i<nums.size();i++)
//         {
//             temp[(i+(nums.size()-rotatecount))%nums.size()]=nums[i];// we have rotated left in order to get the original form.
//         }
//         sort(nums.begin(),nums.end());
//         if(temp==nums) return true;
//         return false;
//     }
// };
// 2nd approach brute force.
class Solution {
public:
    bool check(vector<int>& nums) {
       int count=0;
       for(int i=0;i<nums.size()-1;i++)
       {
           if(nums[i]>nums[i+1]) count++; 
       }
       if(nums[nums.size()-1]>nums[0]) count++;
       if(count<=1) return true; // count =0 is for arrays which have the same value like
       //[1,1,1]
       return false;
    }
};