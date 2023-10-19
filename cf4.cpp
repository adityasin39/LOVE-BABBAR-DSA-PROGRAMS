#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(s=="()")
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        string option1="";
        for(int i=0;i<s.size();i++)
        {
            option1+='(';
        }
         for(int i=0;i<s.size();i++)
        {
            option1+=')';
        }
        string option2="";
          for(int i=0;i<s.size();i++)
        {
            option2+="()";
        }
        if(option1.find(s)!=string::npos) cout<<option2<<endl;
        else cout<<option1<<endl;
    }
    return 0;
}