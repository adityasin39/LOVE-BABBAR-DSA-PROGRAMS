// this question actually is made for Kahn algo as you can see by reading the problem.
// topo sort gives such an ordering which is same as demanded by the problem here.
// if course 0 has to be done before 1 then that means there is an edge from 0 to 1 and the topo sort will make sure that 0 comes before 1 in the answer.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            topo.push_back(temp);
            for(auto it: adj[temp])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size()==numCourses) return topo; // if there is no cycle
        return {}; //if there is a cycle.
    }
};