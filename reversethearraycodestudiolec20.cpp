// boht sochkar formula banaya m+n+1/2 so this is the first approach.
// #include <bits/stdc++.h> 
// void reverseArray(vector<int> &arr , int m)
// {
//     int n=arr.size();
//   for(int i=m+1, j=0;i<(m+n+1)/2;i++,j++) swap(arr[i],arr[n-j-1]);
// }
// bina paaglon ki tarah soche agar two pointer se reverse karta toh kuch sochna hi nahi padta aur direct answer aata.
// 2nd approach.
// #include <bits/stdc++.h> 
// void reverseArray(vector<int> &arr , int m)
// {
//    int s=m+1;
//     int e=arr.size()-1;
//     while(s<=e)
//     {
//         swap(arr[s],arr[e]);
//         s++;
//         e--;
//     }
// }
// using stl reverse function.
// 3rd approach.
#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
 reverse(arr.begin()+(m+1),arr.end());
}
