// if you dont understand then refer to tle eleminators
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(k%2==0)
        {
            sort(s.begin(),s.end());
            cout<<s<<endl;
        }
        else
        {
            string even="";
            string odd="";
            for(int i=0;i<n;i++)
            {
                if(i%2==0) even+=s[i];
                else odd+=s[i];
            }
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            string ans(n,' ');
            int i=0;
            int j=0;
            while(i<n)
            {
                ans[i]=even[j];
                i+=2;
                j++;
            }
            i=1;
            j=0;
             while(i<n)
            {
                ans[i]=odd[j];
                i+=2;
                j++;
            }
            
            cout<<ans<<endl;
        }
    }
    return 0;
}