#include <bits/stdc++.h> 
bool isPossible(vector<int> &rank,int m,int n,int mid)
{
    int pratacount=0;
    int cookcount=0;
    
    for(int i=0;i<n;i++)
    {
        cookcount++;
        int lastprata=rank[i];
        for(int j=2;lastprata<=mid;j++)
        {
            pratacount++;
            if(pratacount==m) return true;
            lastprata+=(j)*rank[i];
        }
        
    }
    return false;
}
int minCookTime(vector<int> &rank, int m)
{
    int n=rank.size();
    int start=0;
    int end=10*(m)*(m+1)/2;
    int res=0;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(rank,m,n,mid))
        {
            res=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
  return res;
}
