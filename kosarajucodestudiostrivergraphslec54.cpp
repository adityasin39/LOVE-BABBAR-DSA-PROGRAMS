#include<bits/stdc++.h>
	void dfs(int node, stack<int>& st, vector<int>& visited, vector<int> adj[])
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
		void dfs2(int node,vector<int>& visited, vector<int> adjT[],vector<int>& scc)
	{
	    visited[node]=1;
        scc.push_back(node);
	    for(auto it: adjT[node])
	    {
	        if(!visited[it])
	        {
	            dfs2(it,visited,adjT,scc);
	        }
	    }
	}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<int> adj[n];
    vector<int> adjT[n];
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
     stack<int> st;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,st,visited,adj);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!visited[node])
            {
                vector<int> scc;
                dfs2(node,visited,adjT,scc);
                ans.push_back(scc);
            }
        }
        return ans;

}