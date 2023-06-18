#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
   //brute force is to run two loops and get all the sums of all the subarrays in a vector
   // and then sort the vector to get the answer. TC=O(n^2) + O(LlogL) the value of L for the vector is actually n^2 so the TC=O(n^2)+O(n^2logn) so all in all TC=O(n^2logn)
   //SC=O(n^2) for the vector of length n^2
   // We can optimize this solution a bit by using a min heap and reducing the SC to O(k) as done in kth largest element.
   //in this approach,
   //TC=O(n^2logk) and SC=O(k) so we have improved a bit.
   priority_queue<int,vector<int>,greater<int>> pq;
   for(int i=0;i<arr.size();i++)
   {
	   int sum=0;
	   for(int j=i;j<arr.size();j++)
	   {
		   sum+=arr[j];
		   if(pq.size()<k)
		   {
			   pq.push(sum);
		   }
		   else{//pq.size()==k
           if(sum>pq.top())
		   {
			   pq.pop();
			   pq.push(sum);
		   }
		   }
	   }
   }
   return pq.top();
}