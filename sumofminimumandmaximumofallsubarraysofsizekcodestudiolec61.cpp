// subarray means contiguous
// if you dont understand then refer to love babbar video
#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	deque<int> maxi;// we make two deques one for max and other for min and in max we store elements in decreasing order whereas in min we store elements in increasing order
	deque<int> mini;
	for(int i=0;i<k;i++)// first window
	{
		while(!maxi.empty() && nums[maxi.back()]<=nums[i]) maxi.pop_back();// to make decreasing order
		while(!mini.empty() && nums[mini.back()]>=nums[i]) mini.pop_back();// to make increasing order
		maxi.push_back(i);
		mini.push_back(i);
	}
	long long ans=0;
	for(int i=k;i<=n;i++)
	{
      ans+=nums[maxi.front()]+nums[mini.front()];
	  if(i==n) break;
	  if(!maxi.empty() && maxi.front()<i-k+1) maxi.pop_front();// removal
	   if(!mini.empty() && mini.front()<i-k+1) mini.pop_front();
	   while(!maxi.empty() && nums[maxi.back()]<=nums[i]) maxi.pop_back();// addition
		while(!mini.empty() && nums[mini.back()]>=nums[i]) mini.pop_back();
		maxi.push_back(i);
		mini.push_back(i);

	} 
	return ans;
}
