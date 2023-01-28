// input- 412
// output - Four One Two
#include<iostream>
using namespace std;
void say(int n, string arr[])
{
    if(n==0) return;
    int digit=n%10;
    say(n/10,arr);
    cout<<arr[digit]<<" "; // recursive call ke baad likha to print in reverse order.
}
int main(){
    int n;
    string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    cout<<"Enter a number"<<endl;
    cin>>n;
    say(n,arr);
    return 0;
}