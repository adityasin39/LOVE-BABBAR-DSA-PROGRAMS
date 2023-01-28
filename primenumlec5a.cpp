#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=2;
    if(n==0||n==1)cout<<"Neither prime nor composite"<<endl;
    for(;i<=n-1;i++)
    {
        if(n%i==0)
        {
            cout<<"composite"<<endl;
            break;
        }
    }
    if(i==n)
    {
        
    
    cout<<"prime";
    }
}