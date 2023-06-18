  // TC=O(V*E) and SC=O(V)
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8);
        dist[S]=0;
        bool negativecycle=false;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<edges.size();j++)
            {
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]) //include dist[u]!=1e8 nahi toh infinity+wt issue kar dega aur wrong answer aa sakta hai.
                {
                    if(i==V-1) negativecycle=true;
                    dist[v]=dist[u]+wt;
                }
            }
        }
        if(negativecycle==true)
        {
          return {-1};
        }
        return dist;
        
    }
};