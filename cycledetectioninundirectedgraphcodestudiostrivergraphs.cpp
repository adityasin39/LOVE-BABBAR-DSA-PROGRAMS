// the logic is same for both bfs and dfs.
// we take a parent node and whenever we find that the neighbouring node is already visited and its nost
// its parent then that node must have been visited by any other node before which means that there is 
// cyclec.
// TC=O(V+2E) and SC=O(V)
//using dfs
#include<bits/stdc++.h>
 bool isPresent(int startingNode,vector<int> adj[],vector<int>& visited, int parent)
    {
        visited[startingNode]=1;
       for(int i=0;i<adj[startingNode].size();i++)
       {
           if(!visited[adj[startingNode][i]])
           {
               if(isPresent(adj[startingNode][i],adj,visited,startingNode)==true) return true;
           }
           else
           {
               if(adj[startingNode][i]!=parent) return true;
           }

       }
       return false;
    }
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==0){
            if(isPresent(i,adj,visited,-1)==true) return "Yes";
            }
        }
        return "No";

}
//using bfs
// #include<bits/stdc++.h>
//  bool isPresent(int startingNode,vector<int> adj[],vector<int>& visited)
//     {
//         queue<pair<int,int>> q;
//         q.push({startingNode,-1});
//         visited[startingNode]=1;
//         while(!q.empty())
//         {
//             int size=q.size();
//             for(int i=0;i<size;i++)
//             {
//                 pair<int,int> temp=q.front();
//                 int node=temp.first;
//                 int parent=temp.second;
//                 q.pop();
//                 for(int j=0;j<adj[node].size();j++)
//                 {
//                     if(visited[adj[node][j]]==1)
//                     {
//                         if(adj[node][j]!=parent) return true;
//                         else continue;
//                     }
//                     q.push({adj[node][j],node});
//                     visited[adj[node][j]]=1;
//                 }
//             }
//         }
//         return false;
//     }
// string cycleDetection (vector<vector<int>>& edges, int n, int m)
// {
//     vector<int> adj[n+1];
//     for(int i=0;i<m;i++)
//     {
//         int u=edges[i][0];
//         int v=edges[i][1];
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> visited(n+1,0);
//         for(int i=1;i<=n;i++)
//         {
//             if(visited[i]==0){
//             if(isPresent(i,adj,visited)==true) return "Yes";
//             }
//         }
//         return "No";

// }
