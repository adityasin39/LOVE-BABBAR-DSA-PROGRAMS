#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
            st.push(s[i]);
        }
        else
        {
            if(s[i]==')')
            {
                if(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/')
                {
                  while (st.top() != '(') {
                    st.pop();
                  }
                  st.pop();
                } else
                  return true;
            }
        }
    }
    return false;
}