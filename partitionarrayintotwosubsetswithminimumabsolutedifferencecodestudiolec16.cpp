// this is for only positive integers
// so tumhe lagega ki har sum ko totalsum/2 se explore kiya jaaye aur min nikala jaaye.
// par agar ek subset ka sum pata hai toh doosre ka totalsum-sum1 se mil jaayega.
// par har sum ke liye subset sum equal to k wale function ko call karne ki zaroorat nahi because if we do tabulation then in the table we actually have all possible sum1.
// we just need to consider till half of the total sum because other combinations will repeat.
// so in tabulation, we give the target as totsum/2
#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum=accumulate(arr.begin(),arr.end(),0);
	int k=totSum/2;
    vector<bool> prev(k+1,false);
    prev[0]=true;
    if(arr[0]<=k) prev[arr[0]]=true;
    for(int i=1;i<n;i++)
    {
        vector<bool> curr(k+1,false);
        curr[0]=true;
        for(int j=1;j<=k;j++)
        {
            bool pick=false;
            if(j>=arr[i]) pick=prev[j-arr[i]];
            bool notpick=prev[j];
            curr[j]=pick||notpick;
        }
        prev=curr;
    }
	int mini=1e9;
    for(int sum1=0;sum1<=k;sum1++)
	{
		if(prev[sum1]==true)
		{
           mini=min(mini,abs(sum1-(totSum-sum1)));
		}
	}
	return mini;
}