class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        vector<int> lastInterval(intervals[0]);
        for(int i=0;i<n-1;i++)
        {
          if(lastInterval[1]>=intervals[i+1][0])
          {
              vector<int> subans={lastInterval[0],max(lastInterval[1],intervals[i+1][1])};
              lastInterval=subans;
          }
          else {
              ans.push_back(lastInterval);
          lastInterval=intervals[i+1];
          }
        }
        ans.push_back(lastInterval);
        return ans;
    }
};