// quick sort is also a divide and conquer algo
// this is an in place and unstable algo
// to understand it better, dry run the code
#include<iostream>
using namespace std;
int partition(int arr[],int start, int end)
{
    int pivot=arr[start]; // first element as pivot
    int cnt=0;
    for(int i=start+1;i<=end;i++)
    {
        if(arr[i]<=pivot) cnt++; // equal elements ko bhi left mein rakhenge
    }
    int pivotcorrectindex=start+cnt;
    swap(arr[pivotcorrectindex],arr[start]); // placing the pivot at its correct position
    int i=start;
    int j=end;
    // left of the pivot will contain smaller or equal elememts and right part will contain greater elements
    while(i<pivotcorrectindex && j>pivotcorrectindex)
    {
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<pivotcorrectindex && j>pivotcorrectindex) swap(arr[i++],arr[j--]); // swap kardenge agar left mein bada and right mein chota element hai toh
    }
    return pivotcorrectindex;
}
void quicksort(int arr[],int start,int end)
{
    // yaha thoda merge sort se ulta hai as sort wala kaam baad mein ho raha hai pehle partition ban raha hai
    // base case
    if(start>=end) return; // hamesha start>=end hi likhna not start==end 
    // partition create karenge
    int p=partition(arr,start,end);
    // left part ko sort karenge
    quicksort(arr,start,p-1);
    // right part ko sort karenge
    quicksort(arr,p+1,end);
    
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
    quicksort(arr,start,end); // int array ko pass karne par reference pass hota hai not copy so original array mein hi change aayega whereas in case of string and vector & use karna padta hai.
    cout<<"The sorted array is--"<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}