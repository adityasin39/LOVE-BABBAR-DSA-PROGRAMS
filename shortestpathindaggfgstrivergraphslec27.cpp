//INTUTION: Finding the shortest path to a vertex is easy if you already know the shortest paths to all the vertices that can precede it. Finding the longest path to a vertex in DAG is easy if you already know the longest path to all the vertices that can precede it.
//Processing the vertices in topological order ensures that by the time you get to a vertex, you've already processed all the vertices that can precede it.
// TC=O(V+E) and SC=O(v)
class Solution {
  private:
  void dfs(vector<pair<int,int>> adj[], vector<int>& visited, int startingNode,stack<int>& st)
  {
      visited[startingNode]=1;
      for(auto it: adj[startingNode])
      {
          if(!visited[it.first])
          {
              dfs(adj,visited,it.first,st);
          }
      }
      st.push(startingNode);
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        stack<int> st;
        vector<int> visited(N,0);
        for(int i=0;i<N;i++)
        {
            if(!visited[i])
            {
                dfs(adj,visited,i,st);
            }
        }
        vector<int> dist(N,1e9); // AGAR INT_MAX KAAM NA KARE TOH USE 1e9
        dist[0]=0;
        while(!st.empty())
        {
            int temp=st.top();
            st.pop();
            for(auto it: adj[temp])
            {
                int node=it.first;
                int wt=it.second;
            if(dist[temp]+ wt< dist[node])
            {
                dist[node]=dist[temp]+wt;
            }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
        
    }
};