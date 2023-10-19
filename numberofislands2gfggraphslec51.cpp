// if you dont understand then refer to striver notes of this lec
class Solution {
  public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
       DisjointSet ds(n*m);
       int cnt=0;
       vector<vector<int>> islands(n,vector<int>(m,0));
       vector<int> ans;
       for(int i=0;i<operators.size();i++)
       {
          int row=operators[i][0];
          int col=operators[i][1];
          if(islands[row][col]==1) ans.push_back(cnt);
          if(!islands[row][col])
          {
              islands[row][col]=1;
              cnt++;
              int delrow[]={-1,0,1,0};
              int delcol[]={0,1,0,-1};
              for(int i=0;i<4;i++)
              {
                  int nrow=row+delrow[i];
                  int ncol=col+delcol[i];
                  if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && islands[nrow][ncol]==1)
                  {
                      int u=m*row+col;
                      int v=m*nrow+ncol;
                      if(ds.findUpar(u)!=ds.findUpar(v))
                      {
                          cnt--;
                          ds.unionbysize(u,v);
                      }
                  }
              }
              ans.push_back(cnt);
          }
          
       }
       return ans;
    }
};