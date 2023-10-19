int mod=1000000007;
class Solution {
public:
    int solve(int idx, int lar, int cost, int n, int m, int k, vector<vector<vector<int>>>& dp)
    {
        if(idx==n)
        {
            if(cost==k) return 1;
            return 0;
        }
        if(cost>k) return 0;
        if(dp[idx][lar][cost]!=-1) return dp[idx][lar][cost];
        long long ans=0;
        for(int i=1;i<=m;i++)
        {
            if(i>lar) ans+=solve(idx+1,i,cost+1,n,m,k,dp);
            else ans+=solve(idx+1,lar,cost,n,m,k,dp);
        }
        return dp[idx][lar][cost]=ans%mod;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(51,vector<vector<int>>(101,vector<int>(51,-1)));
        return solve(0,0,0,n,m,k,dp);
    }
};