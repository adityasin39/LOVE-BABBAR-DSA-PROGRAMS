// // code of 2^n
// // #include<iostream>
// // using namespace std;
// // int power(int n)
// // {
// //     if(n==0) return 1;
// //     return 2*power(n-1);
// // }
// // int main(){
// //     int n;
// //     cin>>n;
// //     int ans=power(n);
// //     cout<<ans<<endl;
// //     return 0;
// // }
// // code of 5 4 3 2 1
// #include<iostream>
// using namespace std;
// void print(int n)
// {
//     if(n==0) return;
//     cout<<n<<endl;
//     print(n-1);

// }
// int main(){
//     int n;
//     cin>>n;
//     print(n);
//     return 0;
// }
// code of 1 2 3 4 5
#include<iostream>
using namespace std;
void print(int n)
{
    if(n==0) return;
    print(n-1);
    cout<<n<<endl;


}
int main(){
    int n;
    cin>>n;
    print(n);
    return 0;
}