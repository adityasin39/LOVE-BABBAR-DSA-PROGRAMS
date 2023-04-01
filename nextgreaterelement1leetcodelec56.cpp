class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
          mp[nums2[i]]= st.empty() ? -1 : st.top();
            st.emplace(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
             ans.emplace_back(mp[nums1[i]]);
        }
        return ans;
    }
};