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
        int mini=min(a,b);
        double sum=((double)(a+b))/2;
        int ans=ceil((sum-mini)/double(c));
        cout<<ans<<endl;
    }
    return 0;
}