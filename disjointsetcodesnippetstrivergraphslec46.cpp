// TC of union and findUpar is O(4alpha) which is as good as a constant.
#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    DisjointSet ds(7);
    ds.unionbysize(1, 2); 
    ds.unionbysize(2, 3); 
    ds.unionbysize(4, 5); 
    ds.unionbysize(6, 7); 
    ds.unionbysize(5, 6); 
    // unionbyrank and unionbysize se path compression nahi hota.
    if(ds.findUpar(3)==ds.findUpar(7)) // findUpar se hi path compress hoga so abhi path compress hoga hence direct parent[node1]==parent[node2] se answer nahi aayega.
    {
        cout<<"Same component"<<endl;
    }
    else cout<<"Not same component"<<endl;
    ds.unionbysize(3,7);
    if(ds.findUpar(3)==ds.findUpar(7)) 
    {
        cout<<"Same component"<<endl;
    }
    else cout<<"Not same component"<<endl;

}