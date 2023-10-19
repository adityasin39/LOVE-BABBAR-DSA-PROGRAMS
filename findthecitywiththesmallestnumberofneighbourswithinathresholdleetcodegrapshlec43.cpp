// you can do via dijkstra too
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,0));
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u][v]=wt;
            adj[v][u]=wt;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]==0) adj[i][j]=1e9;
            }
        }
        for(int i=0;i<n;i++) adj[i][i]=0;
        for(int k=0;k<n;k++){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][k]!=1e9 && adj[k][j]!=1e9)
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
        }
        int ans=INT_MAX;
        int city=-1;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && adj[i][j]<=distanceThreshold)
                {
                   count++;
                }
            }
            if(count<=ans) // equal to because we want the greatest city in case of a tie
            {
                ans=count;
                city=i;
            }
        }
        return city;
    }
};