#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,n;
        cin>>x>>y>>n;
        vector<int> arr(n,-1);
        arr[0]=x;
        arr[n-1]=y;
        int cnt=1;
        for(int i=n-2;i>=1;i--)
        {
            if(arr[i]==-1)
            {
              arr[i]=arr[i+1]-cnt;
            }
            cnt++;
        }
        if(arr[0]>(arr[1]-cnt)) cout<<-1;
        else 
        {
            for(auto it: arr) cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}