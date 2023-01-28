// agar aisa question hota ki find the total no of occurrences of an element in an array then simply do indexlast-indexfirst+1.
#include <bits/stdc++.h> 
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> ans;
    int start=0;
    int end=n-1;
    //For leftmost occurrence.
    int indexfirst=-1;// agar mila hi nahi toh -1 denge isliye -1 se initialize kiya.
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==k)
        {
            indexfirst=mid;
            end=mid-1;//here as we need the leftmost occurrence so as soon as the mid value becomes equal to key , we go to the left part of mid to find the leftmost occurrence so end= mid-1;
        }
        else if(arr[mid]>k) end=mid-1;
        else start=mid+1;
    }
    //For rightmost occurrence.
    start=0;
    end=n-1;
    int indexlast=-1;
       while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==k)
        {
            indexlast=mid;
            start=mid+1;
        }
        else if(arr[mid]>k) end=mid-1;
        else start=mid+1;
       }
    ans=make_pair(indexfirst,indexlast);//or ans.first=indexfirst; ans.second=indexlast;
    return ans;
    
}
// got tle in this as it is checking the duplicacy of the key in a while loop and in some cases where there is a lot of duplicacy it would obviously give tle.
// #include <bits/stdc++.h> 
// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     pair<int,int> ans;
//     int index=0;
//     int indexfirst=0;
//     int indexlast=0;
//     int start=0;
//     int end=n-1;
//     while(start<=end)
//     {
//         int mid=start+(end-start)/2;
//         if(arr[mid]==k) 
//         {
//             index=mid;
//             break;
//         }
//         else if(arr[mid]>k) end=mid-1;
//         else start=mid+1;
//     }
//     int i=index;
//     if(start==end) 
//     {
//         ans=make_pair(-1,-1);
//         return ans;
//     }
//     else
//     {
//         while(index-1>0 && arr[index-1]==arr[index]) i--;
//         indexfirst=i;
//         i=index;
//         while(index+1<n && arr[index]==arr[index+1]) i++;
//         indexlast=i;
//         ans=make_pair(indexfirst,indexlast);
//         return ans;
//        }
//     return ans;
// }