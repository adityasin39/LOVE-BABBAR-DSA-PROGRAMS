#include <bits/stdc++.h> 
void bfs(vector<int>& ans,vector<int>& visited,
vector<int> adj[],int startingNode)
{
    queue<int> q;
    q.push(startingNode);
    visited[startingNode]=1;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            sort(adj[temp].begin(),adj[temp].end()); // as the question demanded that the nodes of the same level should be in sorted order.
            for(int j=0;j<adj[temp].size();j++)
            {
                if(!visited[adj[temp][j]])
                {
                    q.push(adj[temp][j]);
                    visited[adj[temp][j]]=1;
                }
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adj[vertex];
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    vector<int> visited(vertex,0);
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
        {
            bfs(ans,visited,adj,i);
        }
    }
    return ans;

    
}