bool isPossible(vector<int>& dist, double hour,int n,long long mid)
{
    double sumtime=0;
    double time=0;
    int timeint=0;
    for(int i=0;i<n-1;i++)
    {
       time=dist[i]/double(mid);
        timeint=ceil(time);
       sumtime+=timeint;
       if(sumtime>hour) return false;

    }
    time=dist[n-1]/double(mid);
    sumtime+=time;
    if(sumtime>hour) return false;
    return true;
}
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
       long long start=1;
       int n=dist.size();
    //    int sum=0;
    //    for(int i=0;i<n;i++)sum+=dist[i];
    //    int end=ceil(sum/hour);
    int end=INT_MAX;
       int ans=-1;
       while(start<=end)
       {
           long long mid=start+(end-start)/2;
           if(isPossible(dist,hour,n,mid))
           {
               ans=mid;
               end=mid-1;
           }
           else start=mid+1;
       }
       return ans;
    }
};