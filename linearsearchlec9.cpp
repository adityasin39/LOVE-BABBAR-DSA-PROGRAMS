#include<iostream>
using namespace std;
bool linearsearch(int arr[],int size,int key)
{
     for(int i=0;i<size;i++)
     {
          if(arr[i]==key)
          {
            cout<<"Element found at index "<<i<<endl;
            return 1;
          }
     }
     return 0;
}
int main(){
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key to be searched"<<endl;
    cin>>key;
     bool ans=linearsearch(arr,size,key);
    if(ans==0)
    {
        cout<<"Element not found" <<endl;
           }
    return 0;
}