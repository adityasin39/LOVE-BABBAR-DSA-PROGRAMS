// if you dont understand then refer to yogesh shailesh video
class Solution {
public:
    int lowerbound(vector<vector<int>>& jobs, int idx, int n)
    {
        int start=idx+1;
        int end=n-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(jobs[mid][0]>=jobs[idx][1])
            {
               ans=mid;
               end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
    int solve(vector<vector<int>>& jobs, int idx, int n, vector<int>& dp)
    {
        if(idx>n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int nextIdx=lowerbound(jobs,idx,n);
        int pick=jobs[idx][2]+(nextIdx==-1 ? 0 : solve(jobs,nextIdx,n,dp));
        int notpick=solve(jobs,idx+1,n,dp);
        return dp[idx]=max(pick,notpick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         int n=startTime.size();
        vector<vector<int>> jobs(n,vector<int>(3,0));
        for(int i=0;i<n;i++)
        {
            jobs[i][0]=startTime[i];
            jobs[i][1]=endTime[i];
            jobs[i][2]=profit[i];
        }
        sort(jobs.begin(),jobs.end());
        vector<int> dp(n+1,-1);
        return solve(jobs,0,n,dp);
    }
};