// // Approach 1 which is the better one
// // if you dont understand, then refer to https://www.youtube.com/watch?v=w6LcypDgC4w
// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         vector<pair<char,int>> v;
//         for(int i=0;i<s.size();i++)
//         {
//             if(v.empty()==1 || s[i]!=v.back().first) v.push_back({s[i],1});
//             else
//             {
//                 auto it=v.back();
//                 v.pop_back();
//                 v.push_back({s[i],{++it.second}});
//             }
//             if(v.back().second==k) v.pop_back();
//         }
//         string ans="";
//         while(!v.empty())
//         {
//             int x=v.back().second;
//             while(x--) ans+=v.back().first;
//             v.pop_back();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
        
//     }
// };
// Approach 2
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++)
        {
            
            if(st.empty()==1 || s[i]!=st.top().first) st.push({s[i],1});
            else
            {
                auto it=st.top();
                st.pop();
                st.push({s[i],++it.second});

            }
            if(st.top().second==k) st.pop();
        }
        string ans="";
        while(!st.empty())
        {
            int x=st.top().second;
             while(x--) ans+=st.top().first;
             st.pop();
     }
     reverse(ans.begin(),ans.end());
     return ans;

    }
};