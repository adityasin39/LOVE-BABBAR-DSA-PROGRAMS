// here we will be using bfs as we had previously done using dfs
// so will use kahn's algo to do this
// but we will have some modifications
// if we reverse the edges and then do the kahn's algo then we will get our answer.
// this is because as we reverse, indegree of the terminal nodes will become 0 instead of outdegree and then we will push them into the queue
// then as these are safe nodes so we will drop this path for the neighbouring nodes by doing indegree--;
// so as soon as indegree becomes 0 for any neighbour, we know that it is a safe node.
// if you dont understand then refer to striver notes of this lec
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjT[V];
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i]){
                adjT[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> safeNodes(V,0);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            safeNodes[node]=1;
            for(auto it: adjT[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(safeNodes[i]==1) ans.push_back(i);
        }
       return ans;
    }
};