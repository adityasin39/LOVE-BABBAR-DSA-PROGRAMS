class Solution {
public:
int lowerbound(vector<vector<int>>& offers, int idx, int n)
    {
        int start=idx+1;
        int end=n-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(offers[mid][0]>offers[idx][1])
            {
               ans=mid;
               end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
     long long solve(vector<vector<int>>& offers, int idx, int n, vector<long long>& dp)
    {
        if(idx>n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int nextIdx=lowerbound(offers,idx,n);
        long long pick=offers[idx][2]+(nextIdx==-1 ? 0 : solve(offers,nextIdx,n,dp));
        long long notpick=solve(offers,idx+1,n,dp);
        return dp[idx]=max(pick,notpick);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int totaloffers=offers.size();
        sort(offers.begin(),offers.end());
        vector<long long> dp(totaloffers+1,-1);
        return solve(offers,0,totaloffers,dp);
    }
};