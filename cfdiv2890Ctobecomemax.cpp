// if you dont understand then refer to cpwithcpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(vector<ll>& arr, ll mid, ll n, ll k)
{
    for(ll i=0;i<n;i++)
    {
     ll need=mid;
     ll operations=0;
     for(ll j=i;j<n;j++)
     {
        ll more=need-arr[j];
        if(more<1)
        {
            if(operations<=k)
            {
               return true;
            }
            else break;
        }
        operations+=more;
        need--;
     }
    }
    return false;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n,0);
        ll maxi=0;
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
            maxi=max(maxi,arr[i]);
        }
        ll start=maxi;
        ll end=maxi+k;
        ll ans=0;
        while(start<=end)
        {
            ll mid=start+(end-start)/2;
            if(check(arr,mid,n,k))
            {
                start=mid+1;
                ans=mid;
            }
            else end=mid-1;
        }
        cout<<ans<<endl;
    }
}