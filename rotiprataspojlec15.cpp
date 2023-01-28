#include <bits/stdc++.h>
using namespace std;
bool isPossible(int arr[],int noofprata,int noofcooks,int mid)
{
	int pratacount=0;
	int cookcount=0;
	
	for(int i=0;i<noofcooks;i++)
	{
		cookcount++;
		int lastprata=arr[i];
		for(int j=2;lastprata<=mid;j++)
		{
			pratacount++;
			if(pratacount==noofprata) return true;
			lastprata+=(j)*arr[i];
		}
		
	}
	return false;
}
int main() {
	int t;
	cin>>t;
	vector<int> ans;
	while(t--)
	{
	    
	
	int noofprata;
	cin>>noofprata;
	int noofcooks;
	cin>>noofcooks;
	int arr[noofcooks];
	for(int i=0;i<noofcooks;i++) cin>>arr[i];
	int start=0;
	int end=8*(noofprata)*(noofprata+1)/2;
	int res=0;
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		if(isPossible(arr,noofprata,noofcooks,mid))
		{
			res=mid;
			end=mid-1;
		}
		else start=mid+1;
	}
	ans.push_back(res);
	}
	for(int i=0;i<ans.size();i++)
	{
	    cout<<ans[i]<<endl;
	}
	return 0;
}