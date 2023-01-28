
#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;
int getMax(int arr[],int size)
{
int maxi=INT_MIN;//or int max=arr[0]

for(int i=0;i<size;i++)
{
   maxi=max(maxi,arr[i]); // or if(arr[i]>max)max=arr[i]; This(max) is a predefined function in algorithm. You cant keep the names of vaiable and function same thus i have changed the variable name to maxi.

}
return maxi;

}
int getMin(int arr[],int size)
{
int mini=INT_MAX;//or int min=arr[0]
for(int i=0;i<size;i++)
{
    mini=min(mini,arr[i]);//or if(arr[i]<min)min=arr[i];

}
return mini;

}


int main() {
    int size;
    cin>>size;
   int arr[100];//yaha int arr[size ] bhi likh sakta tha but according to love babar variable likhna is a bad practice . Infact acoording to him, it is shittier than int arr[10000000].Hence i have taken larger size instead of writing a variable.

    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int max=getMax(arr,size);
    int min=getMin(arr,size);
    
    cout<<"max is " <<max<<endl;
    cout<<"min is "<<min<<endl;
    return 0;
}