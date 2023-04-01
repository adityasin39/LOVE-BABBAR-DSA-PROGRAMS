queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    for(int i=0;i<k;i++)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    int n=q.size();
    for(int i=0;i<n-k;i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}