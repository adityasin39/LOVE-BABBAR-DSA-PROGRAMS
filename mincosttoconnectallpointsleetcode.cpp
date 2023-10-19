// connect all the points to each other point and then mst
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,int>> adj[points.size()];
        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<points.size();j++)
            {
                if(i!=j){
                int wt=abs(points[i][0]-points[j][0])+ abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,wt});
                }
            }
        }
        int mst=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,-1}});
        vector<int> visited(points.size(),0);
        while(!pq.empty())
        {
            int node=pq.top().second.first;
            int parent=pq.top().second.second;
            int wt=pq.top().first;
            pq.pop();
            if(parent==-1) visited[node]=1;
            else if(!visited[node])
            {
                mst+=wt;
                visited[node]=1;
            }
            else continue;
            for(auto it: adj[node])
            {
                if(!visited[it.first]) pq.push({it.second,{it.first,node}});
            }
        }
        return mst;
    }
};