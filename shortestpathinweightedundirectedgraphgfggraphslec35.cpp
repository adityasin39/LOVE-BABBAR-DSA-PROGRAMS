vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty())
        {
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            for(auto it: adj[node])
            {
                int neighbour=it.first;
                int edgeweight=it.second;
                if(distance+edgeweight<dist[neighbour])
                {
                    dist[neighbour]=distance+edgeweight;
                    pq.push({dist[neighbour],neighbour});
                    parent[neighbour]=node;
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int> ans;
        ans.push_back(n);
        int node=n;
        while(node!=1)
        {
            ans.push_back(parent[node]);
            node=parent[node];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }