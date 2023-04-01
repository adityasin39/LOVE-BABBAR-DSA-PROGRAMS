class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else
            {
                if(s[i]==')' && st.empty()==0 && st.top()=='(')
                {
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        if(st.empty()) return 0;
        int a=0;
        int b=0;
        while(st.empty()==0)
        {
          if(st.top()=='(') a++;
          else b++;
          st.pop();
        }
        return a+b;
    }
};