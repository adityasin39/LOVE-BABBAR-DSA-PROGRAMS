// this is a typical dsu problem. initially i have initialised count as n because initially no node is connected in dsu and then whenever i find an edge i combine them by unionbyrank and then decrease the count. In this way i will get the number of components.
class Solution {
public:
  class DisjointSet
{
   private:
   vector<int> parent,rank,size;
   public:
    int count;
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
       count=n; // initialization
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
    count--; // main step
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(isConnected[i-1][j-1]==1) ds.unionbyrank(i,j);
            }
        }
        return ds.count;
    }
};
// this is better than the below one as here i am using the matrix itself in the dfs
// class Solution {
// public:
//     void dfs(int node, vector<int>& visited, vector<vector<int>>& isConnected, int n)
//     {
//          visited[node]=1;
//          for(int i=0;i<n;i++)
//          {
//              if(isConnected[node-1][i]==1 && node!=i+1 && !visited[i+1]) dfs(i+1,visited,isConnected,n); 
//          }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//         int cnt=0;
//         vector<int> visited(n+1,0);
//         for(int i=1;i<=n;i++)
//         {
//             if(!visited[i])
//             {
//                 cnt++;
//                 dfs(i,visited,isConnected,n);
//             }
//         }
//         return cnt;
//     }
// };
// TC=O(V+2E)
// class Solution {
// public:
//     void dfs(int node, vector<int>& visited, vector<int> adj[])
//     {
//          visited[node]=1;
//          for(auto it: adj[node])
//          {
//              if(!visited[it]) dfs(it,visited,adj);
//          }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//         vector<int> adj[n+1];
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                if(i==j) continue;
//                if(isConnected[i-1][j-1]==1)
//                {
//                    adj[i].push_back(j);
//                }
//             }
//         }
//         int cnt=0;
//         vector<int> visited(n+1,0);
//         for(int i=1;i<=n;i++) // tc will be added not multiplied here with the dfs
//         {
//             if(!visited[i])
//             {
//                 cnt++;
//                 dfs(i,visited,adj);
//             }
//         }
//         return cnt;
//     }
// };