#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    //Brute force->first generate all subarrays and then from i to j calculate all xors and count.
    //TC=O(n^3) and SC=O(1)
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i;j<n;j++)
    //     {
    //         for(int k=i;k<=j;k++)
    //         {
    //             xor=xor^arr[k];
    //             if(xor==x) cnt++;
    //         }
    //     }
    // }
    //better approach
    // here we have used our smartness and calculated xor at the time of moving the j pointer only as it is creating all possible subarrays.
    // TC=O(n^2) and SC=O(1)
    // for(int i=0;i<n;i++)
    // {
    //     xor=0;
    //     for(int j=i;j<n;j++)
    //     {
    //         xor=xor^arr[j];
    //         if(xor==x) cnt++;
    //     }
    // }
    //best approach
    //TC=O(n) and SC=O(n)
    //if you dont understand this then refer to explanation on strivers website of this problem.
    unordered_map<int,int> mp;
    int n=arr.size();
    int xo=0;
    int count=0;
    mp.insert({0,1}); // xor with 0 value and 1 frequency 
    for(int i=0;i<n;i++)
    {
       xo=xo^arr[i];
       if(mp.find(xo^x)!=mp.end()) count+=mp[xo^x];
       mp[xo]++;
    }
    return count;
}