	// this wont be asked for disconnected graphs
	void dfs(int node, stack<int>& st, vector<int>& visited, vector<vector<int>>& adj)// by reference pass karo adj ko nahi toh tle aayega.
	{
	    visited[node]=1;
	    for(auto it: adj[node])
	    {
	        if(!visited[it])
	        {
	            dfs(it,st,visited,adj);
	        }
	    }
	    st.push(node);
	}
		void dfs2(int node,vector<int>& visited, vector<vector<int>>& adjT)
	{
	    visited[node]=1;
	    for(auto it: adjT[node])
	    {
	        if(!visited[it])
	        {
	            dfs2(it,visited,adjT);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<int> visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,st,visited,adj);
            }
        }
        vector<vector<int>> adjT(V);
        for(int i=0;i<V;i++)
        {
            visited[i]=0;
            for(auto it: adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!visited[node])
            {
                scc++;
                dfs2(node,visited,adjT);
            }
        }
        return scc;      
    }
};