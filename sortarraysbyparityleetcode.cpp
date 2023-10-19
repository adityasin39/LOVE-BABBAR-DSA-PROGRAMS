// approach 1
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      int i=0;
      int j=0;
      while(j<nums.size())
      {
          if((nums[j]&1)==0)
          {
              swap(nums[i],nums[j]);
              i++;
              j++;
          }
          else j++;
      }
      return nums;
    }
};
// approach 2
// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         int i=0;
//         int j=nums.size()-1;
//         while(i<j)
//         {
//             if((nums[i]&1)==0 && (nums[j]&1)==0) i++;
//             else if(nums[i]&1 && nums[j]&1) j--;
//             else if((nums[i]&1)==0 && nums[j]&1) 
//             {
//                 i++;
//                 j--;
//             }
//             else
//             {
//                 swap(nums[i],nums[j]);
//                 i++;
//                 j--;
//             }
//         }
//         return nums;
//     }
// };