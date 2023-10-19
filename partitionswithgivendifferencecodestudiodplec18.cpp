//we can have two approaches here.
// the first approach is the best
// if we observe then we get to know that this problem is an extension of count subsets with k
// so in approach 2, i just do the tabulation with target as total sum of the array and as i need sum1 to be greater or equal to sum2 so i start the loop from totSum/2 and check if there is a subset with sum s1 with count greater than 0 and sum2 which is sum1-d. If it exists then i check if sum1+sum2==totSum and then i add it to the answer.
// in the approach 1, we know that s1-s2=d and s1+s2=totSum thus s2=(totSum-d)/2, as totSum and d are constant so we just need to count the number of subsets with target equal to (totSum-d)/2
// you can get s1=(totSum+d)/2 also but it will take more space.
// but you will get wrong answer because count subsets with sum k worked only for postive integers.
// If you achieve the target then it returns 1 but what if you have a case like [0, 0, 1] with sum 1 then you would get answer as 1 whereas the answer is 4
// so you need to check the constraints properly.
// to solve this issue, we have 3 ways
// 1. sort the array in descending order, by doing this you ensure that all the 0s are lined up at the last and as target wont be 0 so they would also be considered for pick and notpick without affecting the target.
// 2. as we need the recursion to pick and notpick 0 too so we shouldnt return as soon as k becomes 0 instead we should go till the last index and in the meanwhile all the 0s in between would be considered for pick and notpick.
// Now, we have to do the same for the last index. If the 0th index is 0 and k is also 0 then we have two options either of picking 0 or not picking so we return 2
// but if the 0th index is not zero then we return 1 normally.
// and then the other case return arr[0]==k  
// so we remove the base case if(k==0) return 1 and make the above changes.
// 3. this way is far better than 2 because in this way, we do the same thing for 0th index too, ie. pick and notpick and then on index<0 we return 1 if k==0
// so the base case looks like this
// if(idx<0) 
//{
//    if(k==0) return 1;
//    return 0;
//}
// Approach 1
// using recursion
// #include <bits/stdc++.h> 
// long long mod=1e9+7;
// int solve(int idx, vector<int>& arr, int k)
// {
// 	if(idx==0)
// 	{
// 		if(arr[0]==0 && k==0) return 2;
// 		if(k==0 || arr[0]==k) return 1;
// 		return 0;
// 	}
// 	long long  pick=0;
// 	if(k>=arr[idx]) pick=solve(idx-1,arr,k-arr[idx])%mod;
// 	long long notpick=solve(idx-1,arr,k)%mod;
// 	return (pick+notpick)%mod;
// }
// int countPartitions(int n, int d, vector<int> &arr) {
//     int totSum=accumulate(arr.begin(),arr.end(),0);
// 	if((totSum-d)&1 || totSum-d<0) return 0;
// 	int sum2=(totSum-d)/2;
// 	return solve(n-1,arr,sum2)%mod;
// }
//using memoization
// #include<bits/stdc++.h>
// long long mod=1e9+7;
// int solve(int idx, vector<int>& arr, int k, vector<vector<int>>& dp)
// {
// 	if(idx==0)
// 	{
// 	if(arr[0]==0 && k==0) return 2;
// 	if(k==0 || arr[0]==k) return 1;
// 	return 0;
// 	}
// 	if(dp[idx][k]!=-1) return dp[idx][k]%mod;
// 	long long pick=0;
// 	if(k>=arr[idx]) pick=solve(idx-1,arr,k-arr[idx],dp)%mod;
// 	long long notpick=solve(idx-1,arr,k,dp)%mod;
// 	return dp[idx][k]=(pick+notpick)%mod;
// }
// int countPartitions(int n, int d, vector<int> &arr) {
//     int totSum=accumulate(arr.begin(),arr.end(),0);
// 	if((totSum-d)&1 || totSum-d<0) return 0;
// 	int sum2=(totSum-d)/2;
// 	vector<vector<int>> dp(n,vector<int>(sum2+1,-1));
// 	return solve(n-1,arr,sum2,dp)%mod;
// }
// using tabulation
#include<bits/stdc++.h>
long long mod=1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=accumulate(arr.begin(),arr.end(),0);
	if((totSum-d)&1 || totSum-d<0) return 0;
	int sum2=(totSum-d)/2;
	vector<vector<int>> dp(n,vector<int>(sum2+1,0));
	if(arr[0]==0) dp[0][0]=2;
    if(arr[0]!=0) dp[0][0]=1;
	if(arr[0]!=0 && arr[0]<=sum2) dp[0][arr[0]]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=sum2;j++) // 0 se start hoga because there is no base case for 0
		{
			long long pick=0;
			if(j>=arr[i]) pick=dp[i-1][j-arr[i]]%mod;
			long long notpick=dp[i-1][j]%mod;
			dp[i][j]=(pick+notpick)%mod;
		}
	}
	return dp[n-1][sum2];
}
// Approach 2
// #include <bits/stdc++.h> 
// long long mod=1e9+7;
// int countPartitions(int n, int d, vector<int> &arr) {
// 	sort(arr.begin(),arr.end());
// 	reverse(arr.begin(),arr.end());
//     int k=accumulate(arr.begin(),arr.end(),0);
// 	vector<vector<int>> dp(n,vector<int>(k+1,0));
// 	for(int i=0;i<n;i++) dp[i][0]=1;
// 	if(arr[0]<=k) dp[0][arr[0]]=1;
// 	for(int i=1;i<n;i++)
// 	{
// 		for(int j=1;j<=k;j++)
// 		{
// 			long long pick=0;
// 			if(j>=arr[i]) pick=dp[i-1][j-arr[i]]%mod;
// 			long long notpick=dp[i-1][j]%mod;
// 			dp[i][j]=(pick+notpick)%mod;
// 		}
// 	}
//     long long cnt=0;
//     for(int sum1=k/2;sum1<=k;sum1++)
//     {
//         if(dp[n-1][sum1]!=0)
//         {
//             int sum2=sum1-d;
//             if(sum1+sum2==k && sum1>=sum2) cnt+=dp[n-1][sum1]%mod;
//         }
//     }
//     return cnt;
// }