// we do simple bfs here by taking a queue and having a ditance array.
// we just compare the current shortest distance with the new distance, if the new distance is smaller then we update and push that element into the queue.
// As we push elements only when the distance is small so we get shortest distances for the further nodes too.
// do a dry run on the example given in the question.
// we start the bfs from the src as we know its shortest distance.
// if the graph is disconnected then the distance is -1 as the other components wont be reachable.
// TC=O(V+E) and SC=O(V)
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(N,1e9);
        dist[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto it: adj[temp])
            {
                if(dist[temp]+1<dist[it])
                {
                    dist[it]=dist[temp]+1;
                    q.push(it);
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