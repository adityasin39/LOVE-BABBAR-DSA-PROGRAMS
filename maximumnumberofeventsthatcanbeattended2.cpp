class Solution {
public:
      int lowerbound(vector<vector<int>>& events, int idx, int n)
    {
        int start=idx+1;
        int end=n-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(events[mid][0]>events[idx][1])
            {
               ans=mid;
               end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
      int solve(vector<vector<int>>& events, int idx, int n, vector<vector<int>>& dp, int k)
    {
        if(k==0) return 0;
        if(idx>n-1) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int nextIdx=lowerbound(events,idx,n);
        int pick=events[idx][2]+(nextIdx==-1 ? 0 : solve(events,nextIdx,n,dp,k-1));
        int notpick=solve(events,idx+1,n,dp,k);
        return dp[idx][k]=max(pick,notpick);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(events,0,n,dp,k);
    }
};