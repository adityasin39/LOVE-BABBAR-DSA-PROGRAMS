// if you dont understand then refer to cpwithcpp 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if(k>31) cout<<0<<endl;
        else
        {
            ll cnt=0;
            for(ll i=n;i>=0;i--)
            {
                ll first=i;
                ll second=n;
                ll j=k-2;
                while(j>=1)
                {
                    ll curr=second-first;
                    if(curr>first) break; 
                    second=first;
                    first=curr;
                    j--;
                }
                if(j==0)
                {
                    cnt++;
                }
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}