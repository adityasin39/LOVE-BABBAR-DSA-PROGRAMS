#include <iostream>
using namespace std;
bool isPossible(int arr[],int n,int m, int mid)
{
	int treecount=0;
	int cutsum=0;
	for(int i=0;i<n;i++)
	{
		if(mid>arr[i]) 
		{
			treecount++;
			continue;
		}
		if(cutsum+(arr[i]-mid)>=m)
		{
			return true;
		}
		else 
		{
		 treecount++;
		 if(treecount>n) return false;
			
			cutsum+=arr[i]-mid;
		}
	}
	return false;
}
int main() {
	 int n,m;
	 cin>>n>>m;
	 int arr[n];
	 for(int i=0;i<n;i++) cin>>arr[i];
	 int start=0;
	 int maxi=arr[0];
	 for(int i=0;i<n;i++) maxi=max(maxi,arr[i]);
	 int end=maxi;
	 int ans=-1;
	 while(start<=end)
	 {
	 	int mid=start+(end-start)/2;
	 	if(isPossible(arr,n,m,mid))
	 	{
	 		ans=mid;
	 		start=mid+1;
	 	}
	 	else end=mid-1;
	 }
	 cout<<ans;
	return 0;
}