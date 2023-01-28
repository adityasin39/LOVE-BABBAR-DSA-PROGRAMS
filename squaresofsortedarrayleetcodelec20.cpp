//Approach 1 which is the most optimized. if you dont understand, refer to https://www.youtube.com/watch?v=FPCZsG_AkUg
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        // humlog ulta isliye fill kar rahe hai taaki pointers ko extreme par rakh sake nahi toh tough padega.
         int i=0;
         int j=nums.size()-1;
         int k=nums.size()-1;
         while(i<=j)
         {
             if(abs(nums[i])<abs(nums[j])) ans[k--]=nums[j]*nums[j--];
            else ans[k--]=nums[i]*nums[i++];
        }
         return ans;
  }
};
//Approach 2 stl
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//            multiset<int> s;
//            for(int i=0;i<nums.size();i++) s.insert(nums[i]*nums[i]);
//           vector<int> ans;
//           for(auto it:s) ans.push_back(it);
//           return ans;
//   }
// };
//Approach 3 stl
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//          vector<int> ans;
//          for(int i=0;i<nums.size();i++) ans.push_back(nums[i]*nums[i]);
//          sort(ans.begin(),ans.end());
//          return ans;
//   }
// };
//Tle maar diya iss approach mein but then too read the solution
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int negativecount=0;
//         while(nums[negativecount]<0) negativecount++;
//         vector<int> negative;
//         for(int i=negativecount-1;i>=0;i--) negative.push_back(abs(nums[i]));
//         int a=negativecount;
//         int b=0;
//         vector<int> ans;
//         while(a<nums.size() && b<negativecount)
//         {
//             if(nums[a]<negative[b])
//             {
//                 ans.push_back(nums[a]*nums[a]);
//                 a++;
//             }
//             else
//             {
//                 ans.push_back(nums[b]*nums[b]);
//                 b++;
//             }
//         }
//         while(a<nums.size())
//         {
//             ans.push_back(nums[a]*nums[a]);
//         }
//         while(b<negativecount) ans.push_back(nums[b]*nums[b]);
//    return ans;
//   }
// };