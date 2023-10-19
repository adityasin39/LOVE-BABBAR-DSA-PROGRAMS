 
class Solution {
public:
int timer=1;
void dfs(int node, int parent, vector<int>& visited, vector<int>& tin,vector<int>& low,vector<vector<int>>& bridges,vector<int> adj[])
{
     visited[node]=1;
     tin[node]=timer;
     low[node]=timer;
     timer++;
     for(auto it: adj[node])
     {
         if(it==parent) continue;
         else if(!visited[it])
         {
             dfs(it,node,visited,tin,low,bridges,adj);
             low[node]=min(low[node],low[it]);
             if(low[it]>tin[node])
             {
                 vector<int> bridge={it,node};
                 bridges.push_back(bridge);
             }
         }
         else low[node]=min(low[node],low[it]);
     }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> visited(n,0);
        vector<vector<int>> bridges;
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,visited,tin,low,bridges,adj);
        return bridges;
    }
};