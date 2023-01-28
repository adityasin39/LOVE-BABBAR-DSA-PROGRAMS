// in this we have to sort 0 and 1 .
// we can have 3 different approaches.
// 1st approach is simply use sort function.
// 2nd approach is using count array.
// 3rd approach is the two pointer approach which is as follows..
#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin>>n;
     int arr[n];
     cout<<"Enter only 0 and 1"<<endl;
     for(int i=0;i<n;i++)
     {
        cin>>arr[i];
     }
     for(int i=0;i<n;i++)
     {
        cout<<arr[i]<<" ";
     }
     cout<<endl;
     int front=0;
     int back=n-1;
     while(front<=back)
     {
        if(arr[front]==0) front++;
        else if(arr[back]==1) back--;
        else
        {
            swap(arr[front],arr[back]);
            front++;
            back--;
        }
     }
     cout<<"After sorting"<<endl;
     for(int i=0;i<n;i++)
     {
        cout<<arr[i]<<" ";
     }

    
    return 0;
}