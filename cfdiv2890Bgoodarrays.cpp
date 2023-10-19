// if you dont understand then refer to cpwithcpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n,0);
        long long nonOneSum=0;
        int cntOnes=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]==1) cntOnes++;
            else nonOneSum+=arr[i]-1;
        }
        if(n==1) cout<<"No"<<endl;
        else if(nonOneSum>=cntOnes) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}