class DisjointSet
{
   private:
   vector<int> parent,rank,size;
   public:
   DisjointSet(int n)
   {
      parent.resize(n+1);
      rank.resize(n+1);
      size.resize(n+1);
      for(int i=0;i<=n;i++) // will work for both 0 and 1 based indexing
      {
        parent[i]=i;
        size[i]=1;
        rank[i]=0;
      }
   }
   int findUpar(int node)
   {
     if(parent[node]==node) return node;
     return parent[node]=findUpar(parent[node]);//path compression
   }
   void unionbyrank(int u, int v)
   {
    int ulp_u=findUpar(u);
    int ulp_v=findUpar(v);
    if(ulp_u==ulp_v) return;
    if(rank[ulp_u]<rank[ulp_v])
    {
        parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_v]<rank[ulp_u])
    {
        parent[ulp_v]=ulp_u;
    }
    else
    {
        parent[ulp_u]=ulp_v;
        rank[ulp_v]++;
    }
   }
   void unionbysize(int u, int v)
   {
    int ulp_u=findUpar(u);
    int ulp_v=findUpar(v);
    if(ulp_u==ulp_v) return;
    if(size[ulp_u]<size[ulp_v])
    {
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else if(size[ulp_v]<=size[ulp_u])
    {
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
   }
};
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                edges.push_back({it[1],{it[0],i}});
            }
        }
        sort(edges.begin(),edges.end());
        int sum=0;
        DisjointSet ds(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i].second.first;
            int v=edges[i].second.second;
            int wt=edges[i].first;
            if(ds.findUpar(u)==ds.findUpar(v)) continue;
            else
            {
                sum+=wt;
                ds.unionbysize(u,v);
            }
        }
        return sum;
    }
};