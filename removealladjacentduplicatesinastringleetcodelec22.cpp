// // Approach 1 
// class Solution {
// public:
//     string removeDuplicates(string s) {
//        stack<char> st;
//        for(int i=0;i<s.size();i++)
//        {
//            if( st.empty()==0 && s[i]==st.top()) st.pop();
//            else
//            st.push(s[i]);
//        } 
//      string ans="";
//      while(!st.empty())
//      {
//           ans+=st.top();// string mein characters append ho sakte hain
//           st.pop();
//      }
//      reverse(ans.begin(),ans.end());
//      return ans;
//     }
// };
// Approach 2
// ganda brute force with a bad runtime.
// class Solution {
// public:
//     string removeDuplicates(string s) {
//         int i=0;
//         int n=s.size();
//         while(i<n-1)
//         {
//             if(s[i]==s[i+1]) 
//             {s.erase(s.begin()+i,s.begin()+i+2);
//             if(i>=1) i--;
//             else i=0;
//             }
//             else i++;
//         }
//         return s;
//     }
// };
// Approach 3 which is a great one
class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==ans.back()) ans.pop_back();
            else ans.push_back(s[i]);
        }
        return ans;
    }
};