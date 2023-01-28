// a^b using recursion
#include<iostream>
using namespace std;
int pow(int a, int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return a*pow(a,b-1);
    else return pow(a*a,b/2);
}
int main(){
    cout<<"Enter a and b"<<endl;
    int a,b;
    cin>>a>>b;
    int ans=pow(a,b);
    cout<<"The ans is "<<ans<<endl;

    return 0;
}
// bubble sort using recursion
// #include<iostream>
// using namespace std;
// void bubblesort(int *arr,int n) // & will not work in case of array so we use *
// {
//    if(n==1) return; // sirf ek element bacha hai to sort so this is the base case
//    for(int i=0;i<n-1;i++)
//    {
//     if(arr[i]>arr[i+1])
//     {
//         swap(arr[i],arr[i+1]); // sirf ek round solve kiya and iss round mein ek largest element apne sahi pos pe aa jaaega aur baaki recursion sambhal lega.

//     }
   
//    }   
//     return bubblesort(arr,n-1);

//     }
//     int main(){
//     cout<<"Enter the size of the array"<<endl;
//     int n;
//     cin>>n;
//     int arr[n];
//     cout<<"Enter the elements of the array"<<endl;
//     for(int i=0;i<n;i++) cin>>arr[i];
//     bubblesort(arr,n);
//     cout<<"The sorted array is :"<<endl;
//     for(int i=0;i<n;i++) cout<<arr[i]<<" ";

//     return 0;
// }
//  reversing a string using a single pointer
// #include<iostream>
// using namespace std;
// void rev(string& s,int i)
// {
//     if(i>s.size()/2) return;
//     swap(s[i],s[s.size()-i-1]);
//     i++;
//     return rev(s, i);
// }

// int main(){
//     string s;
//     cout<<"Enter a string"<<endl;
//     cin>>s;
//     int i=0;
//     rev(s,i);
//     cout<<"The reversed string is "<<s<<endl;
//     return 0;
// }
// reversing a string using two pointers.
// #include<iostream>
// using namespace std;
// void rev(string& s,int left,int right) // pass by reference kiya hai nahi toh sirf copy reverse ho jaati
// {
//     if(left>right) return;
//     swap(s[left],s[right]);
//     left++;
//     right--;
//     return rev(s,left,right);
// }
// int main(){
//     string s;
//     cout<<"Enter a string"<<endl;
//     cin>>s;
//     int left=0;
//     int right=s.size()-1;
//     rev(s,left,right);
//     cout<<"The reversed string is "<<s<<endl;
//     return 0;
// }