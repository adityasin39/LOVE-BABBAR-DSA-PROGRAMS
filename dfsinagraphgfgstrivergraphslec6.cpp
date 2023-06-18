    //TC=O(V+2E) and SC=O(V)
void dfs(vector<int>& ans, int V, vector<int> adj[],vector<int>& visited,int startingNode)
    {
        visited[startingNode]=1;
        ans.push_back(startingNode);
        for(int i=0;i<adj[startingNode].size();i++)
        {
            if(!visited[adj[startingNode][i]])
            {
                int neighbour=adj[startingNode][i];
                dfs(ans,V,adj,visited,neighbour);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(V,0);
        int startingNode=0;
        dfs(ans,V,adj,visited,startingNode);
        return ans;
    }
};