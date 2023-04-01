// if you dont understand then refer to love babbar video
#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  if(str.size()&1) return -1; // if odd number then it is impossible to make it valid
  stack<char> st;
  for(int i=0;i<str.size();i++)
  {
    if (str[i] == '{') {
      st.push(str[i]);
    }
    else if (str[i] == '}' && st.empty()==0 && st.top()=='{')
    {
      st.pop();
    }
    else st.push(str[i]);
  }
  if(st.empty()) return 0;
  int a = 0; // count for {
  int b = 0; // count for }
  // we have four cases
  // case1: {{{.. case2: }}}.. case3: }}}..odd{{..odd case4: }}}..even{{{..even
  while(st.empty()==0) 
  {
    if(st.top()=='{') a++;
    else b++;
    st.pop();
  }
  return (a+1)/2+(b+1)/2;// formula which fits all 4 cases

}