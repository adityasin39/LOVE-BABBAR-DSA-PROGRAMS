  // TC=O(ElogV)
  // For the derivation of the above time complexity refer https://takeuforward.org/data-structure/g-34-dijkstras-algorithm-intuition-and-time-complexity-derivation/
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty())
        {
         int distance=pq.top().first;
         int node=pq.top().second;
         pq.pop();
         for(auto it: adj[node])
         {
             if(distance+it[1]<dist[it[0]])
             {
                 dist[it[0]]=distance+it[1];
                 pq.push({dist[it[0]],it[0]});
             }
         }
        }
        return dist;
        
    }
};