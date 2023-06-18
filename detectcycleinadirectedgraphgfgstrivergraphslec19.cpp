//its better to pass pathvisited by reference to avoid tle
    // TC=O(V+E) SC=O(V)
    // if you dont understand then refer to https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/
    bool check(vector<int>& visited,vector<int> adj[],vector<int>& pathvisited,int startingNode)
    {
        visited[startingNode]=1;
        pathvisited[startingNode]=1;
        for(int i=0;i<adj[startingNode].size();i++)
        {
            if(!visited[adj[startingNode][i]]) 
            {
               if(check(visited,adj,pathvisited,adj[startingNode][i])==true) return true;
            }
            else if(visited[adj[startingNode][i]]==1 && pathvisited[adj[startingNode][i]]==1) return true;
        }
        pathvisited[startingNode]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> pathvisited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(check(visited,adj,pathvisited,i)==true) return true;
            }
        }
        return false;
    }
};