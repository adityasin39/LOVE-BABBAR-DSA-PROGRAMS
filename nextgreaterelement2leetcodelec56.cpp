// Approach 1 in which i have filled the stack first and then done the same thing
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         stack<int> st;
//         int n=nums.size();
//         vector<int> ans;
//         for(int i=n-1;i>=0;i--) st.push(nums[i]);
//         for(int i=n-1;i>=0;i--)
//         {
//             while(!st.empty() && st.top()<=nums[i]) st.pop();
//            st.empty() ? ans.push_back(-1) : ans.push_back(st.top());
//            st.push(nums[i]);
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };
// Approach 2 which is doing the same thing as approach 1 but in a different way by using %
class Solution{
    public:
vector<int> nextGreaterElements(vector<int>& nums) {
   stack<int> st;
   int n=nums.size();
   vector<int> ans(n);
   for(int i=2*n-1;i>=0;i--)
   {
       while(!st.empty() && st.top()<=nums[i%n]) st.pop();
       if(i<n) // this ensures ki stack ascending order mein fill ho jaae before actual comparision
       {
           if(st.empty()) ans[i]=-1;
           else ans[i]=st.top();
       }
       st.push(nums[i%n]);
   }      
   return ans;
    }
};