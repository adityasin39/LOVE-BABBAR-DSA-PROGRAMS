// TC of both the approaches in O(n*2^n)
// Approach 1 using bits and bitmasking
// as a power set has 2^n subsets and similarly in the case of n bit numbers we can have 2^n possibilities with 0 mapped to empty subset and 11.. mapped to subset with all the elements of the set so we can use bits to make the subsets.
// e.g. [1,2,3] will have 8 subsets and also 3 bit numbers will have 8 possibilities
/*
0 ->> 000 ->> []
1 ->> 001 ->> [3]
2 ->> 010 ->> [2]
3 ->> 011 ->> [2,3]
4 ->> 100 ->> [1]
5 ->> 101 ->> [1,3]
6 ->> 110 ->> [1,2]
7 ->> 111 ->> [1,2,3]
*/
// to check if a bit is set or not , first we create its mask and then do the & with the number of which the bits are to be checked for set or reset
// mask can be created by 1<<bit bit is the bit number to be checked
// so finally number&(1<<bit)
// if you still dont understand, then refer to https://www.youtube.com/watch?v=b7AYbpM5YrE
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
       for(int i=0;i<(1<<n);i++) // 1<<n=2^n
       {
           vector<int> sub;
         for(int j=0;j<n;j++)
         {
             if(i&(1<<j)) sub.push_back(nums[n-j-1]);
         }
          ans.push_back(sub);
       }
       return ans;
    }
};
//Approach 2
// // if you dont understand then draw the recursion tree and if you still dont understand then refer to the original love babbar video.
// class Solution {
//     private:
//     void solve(vector<int> nums, vector<int> output,int idx,vector<vector<int>> &ans) 
//     {
//         // base case is when all the elements of nums are included and excluded
//         if(idx>=nums.size())
//         {
//             // before returning, we have to store the output in our ans as this output will be one of the subsequences.
//             ans.push_back(output);
//             return;
//         }
//         // excluding nums[idx]. In this case, we dont have to do anything 
//         solve(nums,output,idx+1,ans);
//         // including nums[idx] in the output.
//         output.push_back(nums[idx]);
//         solve(nums,output,idx+1,ans);
//     }
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans; // will store the final output
//         vector<int> output; // to temporarily store the subset
//         int idx=0; // to traverse thru nums
//         solve(nums,output,idx,ans);
//         return ans;
//     }
// };