#include<iostream>
using namespace std;
void merge(int arr[],int start,int mid,int end)
{
    int mergedarr[end-start+1];
    int i=start;
    int j=mid+1;
    int k=start;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            mergedarr[k++]=arr[i++];
        }
        else mergedarr[k++]=arr[j++];
    }
    while(i<=mid)
    {
        mergedarr[k++]=arr[i++];
    }
      while(j<=end)
    {
        mergedarr[k++]=arr[j++];
    }
    for(int s=start;s<=end;s++) arr[s]=mergedarr[s];

}
void mergesort(int arr[],int s,int e)
{
    if(s>=e) return;
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int main(){
    cout<<"Enter the size of the array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    int start=0;
    int end=n-1;
    mergesort(arr,start,end);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}