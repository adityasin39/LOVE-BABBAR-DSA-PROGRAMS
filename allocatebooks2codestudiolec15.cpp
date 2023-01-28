#include <bits/stdc++.h> 
bool isPossible(int n, int m, vector<int> time,long long mid)
{
    int daycount=1;
    long long lastchap=0;
    for(int i=0;i<m;i++)
    {
        if(lastchap+time[i]<=mid)
        {
            
            lastchap+=time[i];
        }
        else
        {
            daycount++;
            if(daycount>n || time[i]>mid) return false;
            lastchap=time[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long start=0;
    long long sum=0;
    for(int i=0;i<m;i++) sum+=time[i];
    long long end=sum;
    long long ans=0;
    while(start<=end)
    {
        long long mid=start+(end-start)/2;
        if(isPossible(n,m,time,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    return ans;
}