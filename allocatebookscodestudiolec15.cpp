// for any doubt refer to love babbars video.
#include <bits/stdc++.h>
bool isPossible(vector<int> arr, int n, int m,int mid)
{
    int studentCount=1;
    int pagesSum=0;
    for(int i=0;i<n;i++)
    {
        if(pagesSum+arr[i]<=mid)
        {
            pagesSum+=arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount>m || arr[i]>mid) return false;
            pagesSum=0;
            pagesSum=arr[i];
        }

        }
    return true;
    
}
int allocateBooks(vector<int> arr, int n, int m) {
    if(m>n) return -1;
    int start=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int end=sum;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(arr,n,m,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return ans;
}