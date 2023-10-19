class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0;
        int i=0;
        for(int day=1;day<=100000;day++)
        {
            if(pq.empty() && (day>events[n-1][0])) break;
            while((i<n) && (events[i][0]==day))
            {
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && (pq.top()<day)) pq.pop();
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};