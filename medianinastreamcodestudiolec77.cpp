//Brute force is to do insertion sort as it is an online or running algorithm and the numbers sorted already arent touched again so its like placing a card at the right place.
//This is because after sorting we just need to find the middle element to get the median
//The time complexity of brute force will be O(n^2) as to place the element at the right postiino
// will take O(n) time for n elements.
//Optimized approach: Here we have taken two heaps one is the max heap where the max element will be less than or equal to the previous median and the min element of the min heap will be greater than the previous median.
//We will always try to have atmost difference of 1 between max and min heaps. This is because we can easily find out the median just by taking the average in the case of even number of elements.
//The TC will be O(nlogn)
// we always put the greater element than median in the min heap so that the sorted order is maintained but if the min heap has 1 extra element already compared to max heap then min heap top element will be pushed to max heap.
// if you dont understand then refer to love babbar original video.
#include<bits/stdc++.h>
int signum(int a, int b)
{
	if(a==b) return 0;
	else if(a>b) return 1;
	else return -1;
}
void getmedian(int element, priority_queue<int>& small,priority_queue<int, vector<int>, greater<int>>& large,int & median)
{
	switch(signum(small.size(),large.size()))
	{
      case 0:   //both have n size
	  if(element>median)
	  {
		  large.push(element);
		  median=large.top(); //odd number of elemments thats why
	  }
	  else
	  {
		  small.push(element);
		  median=small.top();
	  }
	  break;
	  case 1:
	  if(element>median) // minheap:n+1 and maxheap:n
	  {
		  large.push(element);
		  median=(small.top()+large.top())/2; //even number of elements thats why
	  }
	  else
	  {
		  large.push(small.top());
		  small.pop();
		  small.push(element);
		  median=(small.top()+large.top())/2;
	  }
	  break;
	  case -1:
	  if(element>median) //minheap:n and maxheap:n+1
	  {
		  small.push(large.top());
		  large.pop();
		  large.push(element);
		   median=(small.top()+large.top())/2;
	  }
	  else
	  {
		  small.push(element);
		  median=(small.top()+large.top())/2;
	  }
	}
}
vector<int> findMedian(vector<int> &arr, int n){
   vector<int> ans;
   priority_queue<int> small;
   priority_queue<int, vector<int>, greater<int>> large;
   int median=INT_MIN;
   for(int i=0;i<n;i++)
   {
     getmedian(arr[i],small,large,median);
	 ans.push_back(median);
   }	
   return ans;
}
