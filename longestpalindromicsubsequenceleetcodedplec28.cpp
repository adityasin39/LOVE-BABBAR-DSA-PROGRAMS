// this is same as lcs because if you reverse the string and find the lcs between the two strings then it acutally will be the longest palindromic subsequence.
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        string t="";
        for(int i=m-1;i>=0;i--) t+=s[i];
        int n=t.size();
        vector<int> prev(n+1,0);
        for(int i=1;i<=m;i++)
        {
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n];
    }
};