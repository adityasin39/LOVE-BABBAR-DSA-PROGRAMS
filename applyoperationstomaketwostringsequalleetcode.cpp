class Solution {
public:
    int solve(int i, vector<int>& diff, int x, int left, vector<vector<int>>& dp)
    {
        if(i==diff.size())
        {
            if(left&1) return 1e9;
            else return (left/2)*x;
        }
        if(dp[i][left]!=-1) return dp[i][left];
        int pick=1e9;
        if(i+1<diff.size() && (diff[i+1]-diff[i])<x)
        pick=diff[i+1]-diff[i]+solve(i+2,diff,x,left,dp);
        int notpick=solve(i+1,diff,x,left+1,dp);
        return dp[i][left]=min(pick,notpick);
    }
    int minOperations(string s1, string s2, int x) {
        vector<int> diff;
        for(int i=0;i<s1.size();i++) if(s1[i]!=s2[i]) diff.push_back(i);
        if(diff.size()&1) return -1;
        vector<vector<int>> dp(diff.size()+1,vector<int>(diff.size()+1,-1));
        return solve(0,diff,x,0,dp);
    }
};