 stack<int> st;
    queue<int> ans;
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        ans.push(st.top());
        st.pop();
    }
    return ans;
    // approach 2 using recursion but it gives tle
//  queue<int> solve(queue<int> q)
//  {
//      if(q.empty()) return q;
//      int temp=q.front();
//      q.pop();
//     queue<int> ans= solve(q);
//     ans.push(temp);
//     return ans;
     
//  }
// queue<int> rev(queue<int> q)
// {
//   queue<int> ans= solve(q);
//   return ans;
// }