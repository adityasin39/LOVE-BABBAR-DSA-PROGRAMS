// in this question we have two approaches of which the 2nd approach is the better one
// Approach 1 which has extra space but with same TC
// TC is O(n*n!) and SC is O(n)
// here we are taking extra added array to track the added ones
// so in this approach, we basically have two things, one is the data structure in which we will store the integers and other is the array which we will use to determine if the integer should be added or not
// here we have used recursion+backtracking
// we have marked all the blocks of added array as 0 and as soon as we select an integer we mark it as 1 in the added array so that we dont encounter repetition
// after we reach the base case then its important to unmark the corresponding block of added array and also remove the integer from the data structure for future answers. This is called backtracking
// if you dont understand then refer to https://www.youtube.com/watch?v=YK78FU5Ffjw
class Solution {
    private:
    void solve(vector<vector<int>> &ans,vector<int> nums, vector<int> output, int added[])
    {
        if(output.size()==nums.size())
        {
            ans.push_back(output);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
        
          if(!added[i])
          {
              added[i]=1;
              output.push_back(nums[i]);
              solve(ans,nums,output,added);
              added[i]=0; // backtracking
              output.pop_back(); // backtracking
          }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
       vector<int> output;
       int added[nums.size()];
       for(int i=0;i<nums.size();i++) added[i]=0;
       solve(ans,nums,output,added);
       return ans;
    }
};
// Approach 2 which does not include the added array and involves only swapping
// if you dont understand then refer to original love babbar video or https://www.youtube.com/watch?v=f2ic2Rsc9pU
// SC=O(n!)
// class Solution {
//     private:
//     void solve(vector<int> nums, vector<vector<int>> &ans, int index)
//     {
//         if(index>=nums.size())
//         {
//             ans.push_back(nums);
//             return;
//         }
//         for(int j=index;j<nums.size();j++)
//         {
//             swap(nums[j],nums[index]);
//             solve(nums,ans,index+1);
//             swap(nums[j],nums[index]); // backtracking to make the nums as original for future answers
//         }

//     }
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int index=0;
//         solve(nums,ans,index);
//         return ans;
//     }
// };