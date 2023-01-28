// binary search
#include<iostream>
using namespace std;
bool binarysearch(int arr[],int target,int start,int end)
{
    if(start>end) return false;
    int mid=start+(end-start)/2;
    if(arr[mid]==target) return true;
    else if(arr[mid]<target)return binarysearch(arr,target,mid+1,end);
    else return binarysearch(arr,target,start,mid-1);
    
    
}
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Enter the element to be searched"<<endl;
    int target;
    cin>>target;
    int start=0;
    int end=n-1;
   bool res= binarysearch(arr,target,start,end);
   cout<<res<<endl;
    return 0;
}
// linear search
// #include<iostream>
// using namespace std;
// bool linearsearch(int arr[],int n,int target)
// {
//     if(n==0) return false;
//     if(arr[0]!=target) return linearsearch(arr+1,n-1,target);
//     else return true;
// }

// int main(){
//     int n;
//     cout<<"Enter the size of the array"<<endl;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     cout<<"Enter the element to be searched"<<endl;
//     int target;
//     cin>>target;
//    bool res= linearsearch(arr,n,target);
//    cout<<res<<endl;
//     return 0;
// }
// sum of all the elements of the array
// #include<iostream>
// using namespace std;
// int sumof(int arr[],int n)
// {
//     if(n==1) return arr[0]; 
//   return arr[0]+sumof(arr+1,n-1);
// }

// int main(){
//     int n;
//     cout<<"Enter the size of the array"<<endl;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans=sumof(arr,n);
//     cout<<"The sum is "<<ans<<endl;
//     return 0;
// }
// #include<iostream>
// using namespace std;
// // check if the array is sorted
// bool isSorted(int *arr ,int n) // or int arr[]
// {
//     if(n==1) return true;
//     if(arr[0]>arr[1]) return false;
//     else
//     {
//         bool res= isSorted(arr+1,n-1);
//         return res;
//     }
// }
// // or
// // bool isSorted(int arr[],int n)
// // {

// //     if(n==1) return true;
// //     if(arr[n-1]>=arr[n-2]) 
// //     {
// //     bool res=isSorted(arr,n-1);
// //     return res;

// //     }
// //     else return false;
// //     }
// int main(){
//     int n;
//     cout<<"Enter the size of the array"<<endl;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     bool ans=isSorted(arr,n);
//     cout<<"The ans is "<<ans<<endl;
//     return 0;
// }