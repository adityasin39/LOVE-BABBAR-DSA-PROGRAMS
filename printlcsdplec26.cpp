#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="bc";
    string t="cbccabcc";
    int m=s.size();
        int n=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++) dp[0][i]=0;
        for(int i=0;i<=m;i++) dp[i][0]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=m;
        int j=n;
        string lcs="";
        while(i>0 && j>0)
        {
            if(s[i-1]==t[j-1])
            {
                lcs+=s[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1]) i--;
                else j--;
            }
        }
        reverse(lcs.begin(),lcs.end());
        cout<<lcs<<endl;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}