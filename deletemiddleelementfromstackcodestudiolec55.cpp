// Approach 1: iterative
#include <bits/stdc++.h> 
void deleteMiddle(stack<int>&inputStack, int N){
	
   vector<int> arr;
   for(int i=0;i<ceil(double(N+1)/2);i++)
   {
      int temp=inputStack.top();
      arr.push_back(temp);
      inputStack.pop();
   }
   for(int i=arr.size()-2;i>=0;i--)
   {
      inputStack.push(arr[i]);
   }
   
}
// Approach 2 : recursive
// #include <bits/stdc++.h> 
// void solve(stack<int>&inputStack,int count, int N)
// {
//    // base case
//    if(count==N/2)
//    {
//        inputStack.pop();
//        return;
//    }
//    int temp=inputStack.top();
//    inputStack.pop();
//    solve(inputStack,count+1,N);
//    inputStack.push(temp);
// }
// void deleteMiddle(stack<int>&inputStack, int N){
	
//    int count=0;
//    solve(inputStack,count,N);
   
// }