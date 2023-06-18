#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
     vector<pair<int,int>> adj[vertices];
     for(int i=0;i<vec.size();i++)
     {
         int u=vec[i][0];
         int v=vec[i][1];
         int w=vec[i][2];
         adj[u].push_back({v,w});
         adj[v].push_back({u,w});
     }
     set<pair<int,int>> st;
     vector<int> dist(vertices,INT_MAX);
     dist[source]=0;
     st.insert({0,source});
     while(!st.empty())
     {
         int distance=(st.begin())->first; // pointer hai toh -> use karna hoga
         int node=(st.begin())->second;
         st.erase({distance,node});
         for(auto it: adj[node])
         {
             if(distance+ it.second< dist[it.first])
             {
                 if(dist[it.first]!=INT_MAX)
                 {
                    st.erase({dist[it.first],it.first});
                 }
                 
                 dist[it.first]=distance+it.second;
                 st.insert({dist[it.first],it.first});
             }
         }
     }
     return dist;
}
