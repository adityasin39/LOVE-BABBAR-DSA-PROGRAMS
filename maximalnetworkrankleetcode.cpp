class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
      vector<vector<int>> adj(n,vector<int>(n,0));
      vector<int> degree(n,0);
      for(auto it:roads)
      {
          int u=it[0];
          int v=it[1];
          adj[u][v]=1;
          adj[v][u]=1;
          degree[u]++;
          degree[v]++;
      }   
      int ans=INT_MIN;
      for(int i=0;i<n;i++)
      {
          for(int j=i+1;j<n;j++)
          {
              ans=max(ans, adj[i][j]==1 ? degree[i]+degree[j]-1 : degree[i]+degree[j]);
          }
      }
      return ans;
    }
};