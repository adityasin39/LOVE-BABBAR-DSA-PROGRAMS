class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans;
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
            {
                st.pop();
            }
            if(st.empty()) ans.emplace_back(0);
            else ans.emplace_back(st.top()-i);
            st.emplace(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};