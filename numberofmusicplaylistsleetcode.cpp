// if you dont understand then refer to neetcode for this question
class Solution {
public:
    long long mod=1e9+7;
    int solve(int n, int goal, int k, int usedsongs, vector<vector<long long>>& dp)
    {
        if(goal==0 && usedsongs!=n) return 0;
        if(goal==0) return 1;
        if(dp[goal][usedsongs]!=-1) return dp[goal][usedsongs];
        long long newsongs=0;
        if(n>usedsongs) newsongs=(n-usedsongs)*(long long)solve(n,goal-1,k,usedsongs+1,dp)%mod;
        long long oldsongs=0;
        if(usedsongs>k) oldsongs=(usedsongs-k)*(long long)solve(n,goal-1,k,usedsongs,dp)%mod;
        return dp[goal][usedsongs]=(newsongs+oldsongs)%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(goal+1,vector<long long>(n+1,-1));
        return solve(n,goal,k,0,dp);
    }
};