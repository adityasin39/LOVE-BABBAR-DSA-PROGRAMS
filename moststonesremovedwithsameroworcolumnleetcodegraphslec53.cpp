//HINT 1 :
// Instead of viewing this question as "Remove the maximum number of stones with the same rows and columns", you may take this question to be "What is the number of stones that can be reached from one another, if reaching stone A to stone B requires either stone A and B having same row or column.

// HINT 2 :
// Let us assume that the number of given stones is "num"
// If we look at all the stone clusters connected to one another, what is the number of stones that you can remove?
// Example : In the below given grid, if '0' represents stones
// X X 0 X X
// 0 X 0 X X
// X X X X X
// 0 X X X 0

// We can map all the stones to one another using basic traversal algorithms.
// For EACH SUCH CLUSTER of stones that can be connected in the grid, the number of stones that can be removed is number of stones in that cluster - 1.

// If we now add the number of clusters and all the number of stones that can be remove :-
// (Stones in Cluster 1- 1) + (C2 -1) + (C3 -1) + ......
// = C1 + C2 + C3 +..... - (number of clusters)
// = Total number of stones - Number of Clusters

// Which will be the solution to this problem.
// here we have considered rows and columns as nodes instead of stones because in that case the size of the disjoint set would become m*n leading to 10^4*10^4 giving memory limit exceeded.
// if you dont understand then refer to striver notes of this lec.
class Solution {
public:
    class DisjointSet
{
   public:
   int cnt;
    vector<int> parent,rank,size;
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
    int removeStones(vector<vector<int>>& stones) {
      int noOfstones=stones.size();
      int rowindex=-1;
      int colindex=-1;
      for(auto it: stones)
      {
          rowindex=max(rowindex,it[0]);
          colindex=max(colindex,it[1]);
      }
      DisjointSet ds(rowindex+1+colindex+1);
      for(auto it: stones)
      {
          int row=it[0];
          int col=it[1]+rowindex+1;
          if(ds.findUpar(row)!=ds.findUpar(col)) ds.unionbysize(row,col);
      }
      int cnt=0;
      for(int i=0;i<rowindex+colindex+2;i++)
      {
          if( ds.parent[i]==i && ds.size[i]>1) cnt++; // ds.parent[i]==i is important because path compression nahi hota puri tarah se
      }
      int ans=noOfstones-cnt;
      return ans;
    }
};
// the below solution gives mle
// class Solution {
// public:
//     class DisjointSet
// {
//    private:
//    vector<int> parent,rank,size;
//    public:
//    int cnt;
//    DisjointSet(int n, int stone)
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
//       cnt=stone;
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
//     cnt--;
//    }
// };
//     int removeStones(vector<vector<int>>& stones) {
//         int noOfstones=stones.size();
//         int rowindex=0;
//         int colindex=0;
//         for(auto it: stones)
//         {
//             int i=it[0];
//             int j=it[1];
//             rowindex=max(rowindex,i);
//             colindex=max(colindex,j);
//         }
//         int m=rowindex+1;
//         int n=colindex+1;
//         vector<vector<int>> grid(m,vector<int>(n,0));
//         DisjointSet ds((m+1)*(n+1),noOfstones);
//         for(auto it: stones)
//         {
//             int row=it[0];
//             int col=it[1];
//             grid[row][col]=1;
//         }
//         for(auto it: stones)
//         {
//             int row=it[0];
//             int col=it[1];
//           for(int i=0;i<m;i++) 
//           {
//             if(i==row) continue;
//             if(grid[i][col]==1)
//             {
//                 int u=n*i+col;
//                 int v=n*row+col;
//                 if(ds.findUpar(u)!=ds.findUpar(v)) ds.unionbysize(u,v);
//             }
//           }
//           for(int i=0;i<n;i++)
//           {
//             if(i==col) continue;
//             if(grid[row][i]==1)
//             {
//                 int u=n*row+i;
//                 int v=n*row+col;
//                 if(ds.findUpar(u)!=ds.findUpar(v)) ds.unionbysize(u,v);
//             }
//           }
//         }
//         int noOfComp=ds.cnt;
//         int ans=noOfstones-noOfComp;
//         return ans;
//     }
// };