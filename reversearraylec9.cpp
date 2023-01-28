//1st approach.
#include<iostream>
using namespace std;
void reverseArray(int arr[],int size)
{
   int start=0;
   int end=size-1;
   while(start<=end)
   {
    swap(arr[start],arr[end]);
    start++;
    end--;
   }

}
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    reverseArray(arr,size);
    printArray(arr,size);
    return 0;
//2nd approach.
#include<iostream>
using namespace std;
void reverseArray(int arr[],int size )
{
    int temp;
   for(int i=0;i<size/2;i++)
   {
      temp=arr[i];
      arr[i]=arr[size-i-1];
      arr[size-i-1]=temp;
   }
}
void printArray(int arr[],int size)
{
  for(int i=0;i<size;i++)
  {
    cout<<arr[i]<<endl;
  }
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];

    }
    reverseArray(arr,size);
    printArray(arr,size);
    return 0;
}
