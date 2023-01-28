#include<iostream>
using namespace std;
void fun(int arr[],int size)
{
    
    arr[2]=66;
    cout<<"Printing in fun"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    
}
int main()
{
    int arr[5]={4,2,56,43,5};
    fun(arr,5);
    cout<<"Printing in main"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;
    }
    //As we see here that although we updated the value of arr[2] in fun but when we printed the value of arr[2] in main , then it also got updated.
    //The reason behind this is that we pass the base address of the array during function call and thus it is pass by reference and not pass by value. 
    
    
    return 0;
}