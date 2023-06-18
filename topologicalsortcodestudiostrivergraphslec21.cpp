//using bfs
// Kahn's algorithm
//we will make an indegree array of all the vertices.As we have said that topo sort is only applicable 
// on DAG so we will always have atleast one vertex whose indegree will be 0 as there will be no 
// cycle in the graph.
// the vertices who have 0 indegree will be the first ones in the ordering because they have no incoming edge ie. no vertex has to be placed before them.
// to do a dry run consider my notebook's topological sort(dfs) graph figure.
// jiska bhi indegree 0 hai usko ham queue mein push kar dete hain taki woh hi answer mein pehle aayein.
// uske baad queue se pop karke answer mein push kar denge aur uss vertex ke jitne bhi neighbouring edges jismein iss vertex ne indegree mein contribute kiya hai, woh saare edges ka indegree decrease kar denge by 1 aur iss process mein jaise hi kisi vertex ka indegree 0 hua iska matlab ab woh answer and queue mein aa sakta hai aur baakiyon se pehle aayega.
// It is guaranteed that queue will always have some vertex ie. on decreasing the indegree, one or the other vertex's indegree will become 0.
// TC=O(V+E) and SC=O(4V)
// if you still dont understand then refer to https://takeuforward.org/data-structure/kahns-algorithm-topological-sort-algorithm-bfs-g-22/
#include <bits/stdc++.h> 
void bfs( vector<int> adj[],vector<int>& ans, vector<int>& indegree, int v)
{
    queue<int> q;
	for(int i=0;i<v;i++)
	{
		if(indegree[i]==0) q.push(i);
	}
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		ans.push_back(temp);
		for(auto it: adj[temp])
		{
			indegree[it]--;
			if(indegree[it]==0) q.push(it);
		}
	}
	
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
	vector<int> indegree(v,0);
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
		indegree[v]++;
	}
	vector<int> ans;
	bfs(adj,ans,indegree,v);
    return ans;
}
// using dfs
#include <bits/stdc++.h> 
// TC=O(V+E) and SC=O(2V)
	void dfs(vector<int> adj[], vector<int>& visited, stack<int>& st, int startingNode)
	{
	    visited[startingNode]=1;
	    for(auto it: adj[startingNode])
	    {
	        if(!visited[it])
	        {
	            dfs(adj,visited,st,it);
	        }
	    }
	    st.push(startingNode);
	}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
     vector<int> visited(v,0);
	    stack<int> st;
	    for(int i=0;i<v;i++)
	    {
	        if(!visited[i])
	        dfs(adj,visited,st,i);
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
}