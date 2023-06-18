    //TC=O(V+2E) and SC=O(v)
    // for every vertex,we visit adjacent nodes which is actually the degree.And this will happen for each vertex and we know that total degree=2E.
    // Thus TC=O(V+2E)
    // if you dont understand then refer to https://takeuforward.org/graph/breadth-first-search-bfs-level-order-traversal/
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        q.push(0);
        vector<int> visited(V,0);
        visited[0]=1;
        vector<int> ans;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++){
              int temp=q.front();
               q.pop();
               ans.push_back(temp);
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
        return ans;
    }