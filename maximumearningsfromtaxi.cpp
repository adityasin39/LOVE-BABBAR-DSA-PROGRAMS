class Solution {
public:
     int lowerbound(vector<vector<int>>& rides, int idx, int n)
    {
        int start=idx+1;
        int end=n-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(rides[mid][0]>=rides[idx][1])
            {
               ans=mid;
               end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
     long long solve(vector<vector<int>>& rides, int idx, int n, vector<long long>& dp)
    {
        if(idx>n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int nextIdx=lowerbound(rides,idx,n);
        long long pick=rides[idx][2]+rides[idx][1]-rides[idx][0]+(nextIdx==-1 ? 0 : solve(rides,nextIdx,n,dp));
        long long notpick=solve(rides,idx+1,n,dp);
        return dp[idx]=max(pick,notpick);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int totalrides=rides.size();
        sort(rides.begin(),rides.end());
        vector<long long> dp(totalrides+1,-1);
        return solve(rides,0,totalrides,dp);
    }
};