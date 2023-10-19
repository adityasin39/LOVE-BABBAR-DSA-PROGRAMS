// To generate critical and pseudo-critical lists, we enumerate each edge:

// If deleting the edge and re-calculating the mst again makes mst total weight increase (or can't form mst), then the edge goes into critical list.
// If we force adding the edge to the mst (by first adding the edge to the mst edge set and run the standard MST algorithm for the rest of the edges), and find that the mst doesn't change, then the edge goes into pseudo-critical list. (This is because if an edge can be in any mst, we can always add it to the edge set first, without changing the final mst total weight).
class Solution {
public:
    class DisjointSet
    {
      private:
      public:
      vector<int> parent,size;
      int count;
      DisjointSet(int n)
      {
          parent.resize(n+1);
          size.resize(n+1);
          for(int i=0;i<=n;i++)
          {
              parent[i]=i;
              size[i]=1;
          }
          count=n;
      }
      int findUpar(int node)
      {
          if(parent[node]==node) return node;
          return parent[node]=findUpar(parent[node]);
      }
      void unionbysize(int u, int v)
      {
          int ulp1=findUpar(u);
          int ulp2=findUpar(v);
          if(ulp1==ulp2) return;
          else if(size[ulp1]>=size[ulp2])
          {
              parent[ulp2]=ulp1;
              size[ulp1]+=size[ulp2];
          }
          else
          {
              parent[ulp1]=ulp2;
              size[ulp2]+=size[ulp1];
          }
          count--;
      }
    };
    struct comp{
      bool operator()(vector<int> e1, vector<int> e2){
         return e1[2]<e2[2];
      }
    };
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
            vector<int> critical;
            vector<int> noncritical;
            for(int i=0;i<edges.size();i++)
            {
                edges[i].push_back(i);
            }
            int mst=0;
            DisjointSet ds(n);
            sort(edges.begin(),edges.end(),comp());
            for(auto it: edges)
            {
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(ds.findUpar(u)==ds.findUpar(v)) continue;
                else
                {
                    ds.unionbysize(u,v);
                    mst+=wt;
                }
            }
            for(int i=0;i<edges.size();i++)
            {
                int mst1=0;
                DisjointSet ds1(n);
                for(auto it: edges)
            {
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                int index=it[3];
                if(index==i || ds1.findUpar(u)==ds1.findUpar(v)) continue;
                else
                {
                    ds1.unionbysize(u,v);
                    mst1+=wt;
                }
            }
               if(ds1.count>1 || mst1>mst) critical.push_back(i);
               else{
               int mst2=0;
                DisjointSet ds2(n);
                for(auto it:edges)
                {
                   if(it[3]==i)
                   {
                       ds2.unionbysize(it[0],it[1]);
                       mst2+=it[2];
                       break;
                   }
                }
                for(auto it: edges)
            {
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                int index=it[3];
                if(ds2.findUpar(u)==ds2.findUpar(v)) continue;
                else
                {
                    ds2.unionbysize(u,v);
                    mst2+=wt;
                }
            }
                if(mst2==mst) noncritical.push_back(i);
               }
            }
            return {critical,noncritical};
    }
};