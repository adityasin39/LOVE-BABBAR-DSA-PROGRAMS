class Solution {
public:
    bool solve(vector<int>& stones, int idx, int jump, vector<vector<int>>& dp)
    {
        if(idx==stones.size()-1) return true;
        if(dp[idx][jump]!=-1) return dp[idx][jump];
        bool firstcase=false;
        bool secondcase=false;
        bool thirdcase=false;
        if(jump!=0 && jump!=1){
        int nextval1=stones[idx]+jump-1;
        int nextIdx1=lower_bound(stones.begin(),stones.end(),nextval1)-stones.begin();
        int value1=-1;
        if(nextIdx1!=stones.size()) value1=stones[nextIdx1];
        if(nextval1==value1) firstcase=solve(stones,nextIdx1,jump-1,dp);
        }
        if(jump!=0){
        int nextval2=stones[idx]+jump;
        int nextIdx2=lower_bound(stones.begin(),stones.end(),nextval2)-stones.begin();
        int value2=-1;
        if(nextIdx2!=stones.size()) value2=stones[nextIdx2];
        if(nextval2==value2) secondcase=solve(stones,nextIdx2,jump,dp);
        }
        int nextval3=stones[idx]+jump+1;
        int nextIdx3=lower_bound(stones.begin(),stones.end(),nextval3)-stones.begin();
        int value3=-1;
        if(nextIdx3!=stones.size()) value3=stones[nextIdx3];
        if(nextval3==value3) thirdcase=solve(stones,nextIdx3,jump+1,dp);
        return dp[idx][jump]=firstcase || secondcase || thirdcase;
    }
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size()+1,vector<int>(stones.size()+1,-1));
        return solve(stones,0,0,dp);
    }
};