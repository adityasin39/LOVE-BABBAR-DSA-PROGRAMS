void dfs(vector<int>& ans, vector<int> adj[],vector<int>& visited,int startingNode)
    {
        visited[startingNode]=1;
        ans.push_back(startingNode);
        for(int i=0;i<adj[startingNode].size();i++)
        {
            if(!visited[adj[startingNode][i]])
            {
                int neighbour=adj[startingNode][i];
                dfs(ans,adj,visited,neighbour);
            }
        }
    }
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
      vector<int> adj[V];
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    vector<int> visited(V,0);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            vector<int> subans;
            dfs(subans,adj,visited,i);
            ans.push_back(subans);
        }
    }
    //you dont need to have the number of components in your answer.They themselves add it.
    return ans;
}