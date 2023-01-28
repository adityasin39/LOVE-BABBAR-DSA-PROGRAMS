// //1st approach.
// #include<iostream>
// using namespace std;
// void swapAlternate(int arr[],int size)
// {
// int i=0;
// int j=1;
// while(j<=(size-1))
// {
//     swap(arr[i],arr[j]);
//     i+=2;
//     j+=2;
// }
// }
// void printArray(int arr[],int size)
// {
//     cout<<"Printing the array"<<endl;
//     for(int i=0;i<size ;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }

// int main(){
//     int size;
//     cin>>size;
//     int arr[size];
//     for(int i=0;i<size;i++)
//     {
//         cin>>arr[i];
//     }
//     swapAlternate(arr,size);
//     printArray(arr,size);
//     return 0;
// }
//2nd approach.
#include<iostream>
using namespace std;
void swapAlternate(int arr[],int size)
{

for(int i=0;i<size;i+=2)
{

if(i+1<size)
    swap(arr[i],arr[i+1]);
}   
}

void printArray(int arr[],int size)
{
    cout<<"Printing the array"<<endl;
    for(int i=0;i<size ;i++)
    {
        cout<<arr[i]<<" ";
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
    swapAlternate(arr,size);
    printArray(arr,size);
    return 0;
}
