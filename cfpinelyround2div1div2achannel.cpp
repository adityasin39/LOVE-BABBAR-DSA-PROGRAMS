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
        int cnt=a;
        int total=a;
        bool done=false;
        if(a==n) done=true;
        for(int i=0;i<q;i++)
        {
            if(s[i]=='+')
            {
                cnt++;
                total++;
                if(cnt>=n) done=true;
            }
            else cnt--;
        } 
        if(total>=n)
        {
            if(done) cout<<"YES"<<endl;
            else cout<<"MAYBE"<<endl;
        }
        else cout<<"NO"<<endl;
        
    }
    return 0;
}
