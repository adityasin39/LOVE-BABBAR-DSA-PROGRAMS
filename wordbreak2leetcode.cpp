class Solution {
public:
    void solve(string& s, vector<string>& wordDict, unordered_set<string>& st, int start, vector<string>& ans, int n, string& res)
    {
        if(start==n)
        {
            ans.push_back(res);
            return;
        }
        for(int end=start+1;end<=n;end++)
        {
            if(st.count(s.substr(start,end-start)))
            {
                res+=s.substr(start,end-start);
                res+=' ';
                solve(s,wordDict,st,end,ans,n,res);
                res.pop_back();
                int i=res.size()-1;
                while(i>=0 && res[i]!=' ') i--;
                res.erase(i+1,end-start);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        string res="";
        solve(s,wordDict,st,0,ans,n,res);
        for(int i=0;i<ans.size();i++) ans[i].pop_back();
        return ans;
    }
};