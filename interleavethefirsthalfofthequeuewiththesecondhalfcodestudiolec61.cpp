// using stack only
#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    stack<int> st;
    int n=q.size();
    for(int i=0;i<n/2;i++)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<n/2;i++)
    {
        q.push(q.front());
        q.pop();
    }
     for(int i=0;i<n/2;i++)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}
// using a queue and a better approach
// #include <bits/stdc++.h> 
// void interLeaveQueue(queue < int > & q) {
//       queue<int> newq;
//       int n=q.size();
//       for(int i=0;i<n/2;i++)
//       {
//           newq.push(q.front());
//           q.pop();
//       }
//       while(!newq.empty())
//       {
//           q.push(newq.front());
//           newq.pop();
//           q.push(q.front());
//           q.pop();
//       }
// }