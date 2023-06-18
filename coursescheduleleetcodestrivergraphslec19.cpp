class Solution {
    private:
    bool dfs(vector<int> adj[],vector<int>& visited, vector<int>& pathvisited,int startingNode)
    {
       visited[startingNode]=1;
       pathvisited[startingNode]=1;
       for(int i=0;i<adj[startingNode].size();i++)
       {
           if(visited[adj[startingNode][i]]==0)
           {
               if(dfs(adj,visited,pathvisited,adj[startingNode][i])==false) return false;
           }
           else if(visited[adj[startingNode][i]]==1 && pathvisited[adj[startingNode][i]]==1) return false;
       }
       pathvisited[startingNode]=0;
       return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int> visited(numCourses,0);
        vector<int> pathvisited(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
               if(dfs(adj,visited,pathvisited,i)==false) return false;
             }
        }
        return true;
    }
};