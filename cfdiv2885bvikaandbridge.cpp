//here binary search on answer will give tle so use normal logic
// if you dont understand then refer to cpwithcpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<priority_queue<ll>> dist(k);
        vector<ll> lastIndex(k,-1);
        for(ll i=0;i<n;i++)
        {
            ll color;
           cin>>color;
           ll jump=i-lastIndex[color-1]-1;
           lastIndex[color-1]=i;
           dist[color-1].push(jump);
        }
        for(ll i=0;i<k;i++)
        {
            ll jump=n-lastIndex[i]-1;
            dist[i].push(jump);
        }
        ll ans=n;
        for(ll i=0;i<k;i++)
        {
            ll largest=dist[i].top();
            dist[i].pop();
            ll secondLargest=dist[i].top();
            ans=min(ans,max(largest/2,secondLargest));
        }
        cout<<ans<<endl;
    }
    return 0;
}