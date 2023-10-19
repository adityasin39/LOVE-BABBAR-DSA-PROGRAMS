// class Solution {
// public:
//     bool solve(string& s, vector<string>& wordDict, unordered_set<string>& st, int start, int n, vector<int>& dp)
//     {
//        if(start==n) return true;
//        if(dp[start]!=-1) return dp[start];
//        for(int end=start+1;end<=n;end++)
//        {
//            if(st.count(s.substr(start,end-start)))
//            {
//                if(solve(s,wordDict,st,end,n,dp)) return dp[start]=true;
//            }
//        }
//        return dp[start]=false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> st(wordDict.begin(),wordDict.end());
//         int n=s.size();
//         vector<int> dp(n+1,-1);
//         return solve(s,wordDict,st,0,n,dp);
//     }
// };
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        for(int start=n-1;start>=0;start--)
        {
            for(int end=start+1;end<=n;end++)
            {
                if(st.count(s.substr(start,end-start))) 
                {
                    if(dp[end])
                    {
                        dp[start]=true;
                    }
                }
            }
        }
        return dp[0];
    }
};