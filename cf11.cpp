#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        bool check=false;
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i]=='0' && b[i]=='0' && a[i+1]=='1' && b[i+1]=='1')
            {
                check=true;
                break;
            }
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
      
    }
    return 0;
}