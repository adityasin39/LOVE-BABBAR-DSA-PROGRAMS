#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long p[n];
    for(int i=0;i<n;i++) cin>>p[i];
    set<long long> s[4];
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        s[x].insert(p[i]);
    }
     for(int i=0;i<n;i++)
    {
        cin>>x;
        s[x].insert(p[i]);
    }
    int m;
    cin>>m;
    int y;
    for(int i=0;i<m;i++)
    {
      cin>>x;
      auto it=s[x].begin();
      if(it==s[x].end()) cout<<-1<<" ";
      else{
        y=*it;
        cout<<y<<" ";
        s[1].erase(y);
        s[2].erase(y);
        s[3].erase(y);
      }
    }
}