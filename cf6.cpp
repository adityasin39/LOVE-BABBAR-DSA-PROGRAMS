#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,q;
        cin>>n>>a>>q;
        string s;
        cin>>s;
        int cnt=0;
        int cnt1=0;
        int j=1;
        while((j+1)<q && s[j]==s[j+1] && s[j]=='+')
        {
            j++;
            cnt1++;
        }
        for(int i=0;i<q;i++)
        {
            if(s[i]=='+') cnt++;
        }
        if((a+cnt1)>=n) cout<<"Yes"<<endl;
        else if((a+cnt)>n) cout<<"YES"<<endl;
        else if((a+cnt)==n) cout<<"MAYBE"<<endl;
        else if((a+cnt)<n) cout<<"NO"<<endl;
    }
    return 0;
}
