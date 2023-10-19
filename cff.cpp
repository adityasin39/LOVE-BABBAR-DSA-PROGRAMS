#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int mini=INT_MAX;
        mini=min(mini,a);
        mini=min(mini,b);
        mini=min(mini,c);
        int cnt=0;
        if(a%mini!=0 || b%mini!=0 || c%mini!=0) cout<<"NO"<<endl;
        else{
            cnt+=a/mini-1;
            cnt+=b/mini-1;
            cnt+=c/mini-1;
            if(cnt>3) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}