#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll cnt=0;
        for(ll i=1;i<=n;i++)
        {
            if(n%i==0)
            {
                cnt++;
            }
            else break;
        }
        cout<<cnt<<endl;
    }
    return 0;
}