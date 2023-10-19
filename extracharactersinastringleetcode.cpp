// if you dont understand then refer to the editorial
// class Solution {
// public:
//     int solve(string& s, unordered_set<string>& st, int start, unordered_map<int,int>& dp)
//     {
//         if(start==s.size()) return 0;
//         if(dp.count(start)) return dp[start];
//         int extra=1+solve(s,st,start+1,dp);
//         int notextra=INT_MAX;
//         for(int end=start+1;end<=s.size();end++)
//         {
//             if(st.count(s.substr(start,end-start)))
//             {
//                 notextra=min(notextra,solve(s,st,end,dp));
//             }
//         }
//         return dp[start]=min(extra,notextra);
//     }
//     int minExtraChar(string s, vector<string>& dictionary) {
//         unordered_map<int,int> dp;
//         unordered_set<string> st(dictionary.begin(),dictionary.end());
//         return solve(s,st,0,dp);
//     }
// };
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<int,int> dp;
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        dp[s.size()]=0;
        for(int start=s.size()-1;start>=0;start--)
        {
            int extra=1+dp[start+1];
            int notextra=INT_MAX;
            for(int end=start+1;end<=s.size();end++)
            {
                if(st.count(s.substr(start,end-start))) notextra=min(notextra,dp[end]);
            }
            dp[start]=min(extra,notextra);
        }
        return dp[0];
    }
};