class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times) adj[it[0]].push_back({it[1],it[2]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int distance=it.first;
            int node=it.second;
            for(auto i: adj[node])
            {
                int time=i.second;
                if(time+distance<dist[i.first])
                {
                    dist[i.first]=time+distance;
                    pq.push({dist[i.first],i.first});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++) ans=max(ans,dist[i]);
        if(ans==1e9) return -1;
        return ans;
    }
};