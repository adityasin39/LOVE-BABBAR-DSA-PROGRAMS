// recursive backtracking tle code
// void solve(int i, int j, string& s, string& t, set<string>& ans, string lcs, vector<vector<int>>& dp)
// 	    {
// 	        if(i==0 || j==0)
// 	        {
// 	            reverse(lcs.begin(),lcs.end());
// 	            ans.insert(lcs);
// 	            return;
// 	        }
// 	        if(s[i-1]==t[j-1])
// 	        {
// 	            lcs+=s[i-1];
// 	           solve(i-1,j-1,s,t,ans,lcs,dp);
// 	        }
// 	        else
// 	        {
// 	            if(dp[i-1][j]>dp[i][j-1])
// 	            {
// 	              solve(i-1,j,s,t,ans,lcs,dp);
// 	            }
// 	            else if(dp[i][j-1]>dp[i-1][j])
// 	            {
// 	                 solve(i,j-1,s,t,ans,lcs,dp);
// 	            }
// 	            else // dp[i-1][j]==dp[i][j-1]
// 	            {
// 	               solve(i-1,j,s,t,ans,lcs,dp);
// 	               solve(i,j-1,s,t,ans,lcs,dp);
// 	            }
// 	        }
// 	    }
// 		vector<string> all_longest_common_subsequences(string s, string t)
// 		{
// 		   int m=s.size();
//         int n=t.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         for(int i=0;i<=n;i++) dp[0][i]=0;
//         for(int i=0;i<=m;i++) dp[i][0]=0;
//         for(int i=1;i<=m;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
//                 else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//          set<string> ans;
//          string lcs="";
//          solve(m,n,s,t,ans,lcs,dp);
//          vector<string> res;
//          for(auto it: ans) res.push_back(it);
//          return res;
// 		} 
// accepted tabulation code
{
	public:
	    vector<string> all_longest_common_subsequences(string s, string t) {
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    vector<vector<set<string>>> sequences(m+1,vector<set<string>>(n+1));
    for(int i=0;i<=m;i++) sequences[i][0].insert("");
    for(int j=0;j<=n;j++) sequences[0][j].insert("");
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==t[j-1])
            {
                for(auto it: sequences[i-1][j-1])
                {
                    it+=s[i-1];
                    sequences[i][j].insert(it);
                }
            }
            else
            {
                if(dp[i-1][j]>=dp[i][j-1])
                {
                   sequences[i][j]=sequences[i-1][j];   
                }
                if(dp[i][j-1]>=dp[i-1][j])
                {
                    sequences[i][j].insert(sequences[i][j-1].begin(),sequences[i][j-1].end());
                }
            }
        }
    }
    vector<string> ans={sequences[m][n].begin(),sequences[m][n].end()};
    return ans;
    
		}