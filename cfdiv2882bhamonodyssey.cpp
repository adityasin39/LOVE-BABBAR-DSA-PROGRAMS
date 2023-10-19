// if you dont understand then refer to cpwithcpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n,0);
		for(int i=0;i<n;i++)
		{
		   cin>>arr[i];
		}
	    int res=arr[0];
	    for(int i=1;i<n;i++)
	    {
	    	res=res&arr[i];
	    }
		if(res!=0) cout<<1<<endl;
		else
		{
			int cnt=0;
			int i=0;
			while(i<n)
			{
		     int temp=arr[i];
			while(i<n && ((temp&arr[i])!=0))
			{
				temp=temp&arr[i];
				i++;
			}
			if(i!=n)
			{
				cnt++;
				i++;
			}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}