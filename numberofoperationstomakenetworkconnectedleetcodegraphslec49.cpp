// here i have two approaches which are actually the same but the approach 1 is better.
// if you observe carefully then you will get to know that if you calculate the number of components then no of components -1 will be the ans if the edges in the connections graph are sufficient enough.
// suppose the connections graph has n nodes then to atleast keep the connections graph connected, we require n-1 edges.But we have to connect all the components so if we have atleast n-1+noofComp-1 edges then we can say that the components can be connected via noOfComp-1 wires.This is done in approach 2
// in approach 1, while building the graph, if we find that two nodes have the same ulimate parent already then that means that they are already connected so that is an extra edge that i was talking about other than the n-1 required edges.if such extra edges are equal or greater than noOfComp-1 then we can connect.
// Approach 1
class Solution {
public:
    class DisjointSet
{
   private:
   vector<int> parent,rank,size;
   public:
   int cnt;
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
      cnt=n;
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
    cnt--;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges=0;
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            if(ds.findUpar(u)==ds.findUpar(v))
            {
                extraEdges++;
            }
            else ds.unionbyrank(u,v);
        }
        int noOfComp=ds.cnt;
        int ans=noOfComp-1;
        if(extraEdges>=ans) return ans;
        return -1;
    }
};
// Approach 2
// class Solution {
// public:
//     class DisjointSet
// {
//    private:
//    vector<int> parent,rank,size;
//    public:
//    int cnt;
//    DisjointSet(int n)
//    {
//       parent.resize(n+1);
//       rank.resize(n+1);
//       size.resize(n+1);
//       for(int i=0;i<=n;i++) // will work for both 0 and 1 based indexing
//       {
//         parent[i]=i;
//         size[i]=1;
//         rank[i]=0;
//       }
//       cnt=n;
//    }
//    int findUpar(int node)
//    {
//      if(parent[node]==node) return node;
//      return parent[node]=findUpar(parent[node]);//path compression
//    }
//    void unionbyrank(int u, int v)
//    {
//     int ulp_u=findUpar(u);
//     int ulp_v=findUpar(v);
//     if(ulp_u==ulp_v) return;
//     if(rank[ulp_u]<rank[ulp_v])
//     {
//         parent[ulp_u]=ulp_v;
//     }
//     else if(rank[ulp_v]<rank[ulp_u])
//     {
//         parent[ulp_v]=ulp_u;
//     }
//     else
//     {
//         parent[ulp_u]=ulp_v;
//         rank[ulp_v]++;
//     }
//     cnt--;
//    }
//    void unionbysize(int u, int v)
//    {
//     int ulp_u=findUpar(u);
//     int ulp_v=findUpar(v);
//     if(ulp_u==ulp_v) return;
//     if(size[ulp_u]<size[ulp_v])
//     {
//         parent[ulp_u]=ulp_v;
//         size[ulp_v]+=size[ulp_u];
//     }
//     else if(size[ulp_v]<=size[ulp_u])
//     {
//         parent[ulp_v]=ulp_u;
//         size[ulp_u]+=size[ulp_v];
//     }
//    }
// };
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         DisjointSet ds(n);
//         vector<int> nodes(n,0); // to find the number of nodes in the connections graph
//         for(int i=0;i<connections.size();i++)
//         {
//             int u=connections[i][0];
//             int v=connections[i][1];
//             nodes[u]=1;
//             nodes[v]=1;
//             ds.unionbyrank(u,v);
//         }
//         int noOfComp=ds.cnt;
//         int totalEdges=connections.size();
//         int totalNodes=0;
//         for(int i=0;i<n;i++)
//         {
//             if(nodes[i]==1) totalNodes++;
//         }
//         if(totalEdges < totalNodes-1+noOfComp-1) return -1;
//         return noOfComp-1;
//     }
// };