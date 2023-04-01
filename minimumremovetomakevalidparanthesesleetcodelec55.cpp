// Approach 1 without stack best approach TC=O(n) and SC=O(1)
// we have taken a variable which counts the number of invalid open braces and have marked invalid ) as * and then as the string would be balanced from the front side so we traverse from the back side and mark the ( as * and then remove *
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openbraces=0;
        for(int i=0;i<s.size();i++)
        {
          if(s[i]=='(') openbraces++;
          if(s[i]==')')
          {
            if(openbraces>0) openbraces--;
            else s[i]='*';
          }
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        cout<<s<<endl;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
          if(openbraces>0 && s[i]=='(')
          {
            s[i]='*';
            openbraces--;
          }
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
    }
};
// Approach 2 with stack TC=O(n) and SC=O(n)
// jitne bhi invalid ) and stack mein left out ( ko * mark karke remove kar rahe hain
// class Solution {
// public:
//     string minRemoveToMakeValid(string s) {
//         stack<int> st;
//         for(int i=0;i<s.size();++i)
//         {
//           if(s[i]=='(')
//           {
//             st.push(i);
//           }
//           if(s[i]==')')
//           {
//             if(st.empty()==0)
//             {
//               st.pop();
//             }
//             else s[i]='*';
//           }
//         }
//         while(st.empty()==0)
//         {
//           s[st.top()]='*';
//           st.pop();
//         }
//         s.erase(remove(s.begin(),s.end(),'*'),s.end());
//         return s;
//     }
// };