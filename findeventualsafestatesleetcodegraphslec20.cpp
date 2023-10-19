// dfs Approach:
// on observing some graphs, you will realize that if there is a cycle then the nodes in the cycle will be unsafe nodes.
// this is because if you get a cycle, then that means that there is a path which does not end on a terminal node.
// So the algo is as follows:
// run a single dfs and use the same concept of cycle detection in a directed graph using dfs.
// if you explore all the paths and if you dont find a cycle then that means that node is definitely a safe node. So whenever you come out of the loop of the dfs then that means that you didnt get a cylce so the node from which you will return is definitely a safe node.
// And if a node has an adjacent node which is a safe node then no need to explore that path because it means that there will be no cycle because there was no cycle from that adjacent node.
// if a node has an adjacent node which is unsafe then no need to explore the remaining paths because this too will be a unsafe node so return false;
// so ultimately the nodes which are part of a cycle and the nodes which have a path into the cycle are unsafe nodes.
// if you dont understand then refer to striver notes of this lec.
class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<int>& pathvisited, vector<int>& safeNodes,vector<vector<int>>& graph)
    {
        visited[node]=1;
        pathvisited[node]=1;
        for(auto it: graph[node])
        {
            if(safeNodes[it]==1) continue;
            if(!visited[it]) 
            {
                if(dfs(it,visited,pathvisited,safeNodes,graph)==false) return false;
            }
            else if(visited[it]==1 && pathvisited[it]==1) return false;
        }
        pathvisited[node]=1;
        safeNodes[node]=1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> pathvisited(n,0);
        vector<int> safeNodes(n,0);
        for(int i=0;i<n;i++)
        {
           if(!visited[i]) dfs(i,visited,pathvisited,safeNodes,graph);
        }      
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(safeNodes[i]==1) ans.push_back(i);
        }
        return ans;
    }
};