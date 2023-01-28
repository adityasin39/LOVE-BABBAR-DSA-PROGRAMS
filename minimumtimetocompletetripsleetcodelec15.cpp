bool isPossible(vector<int>& time, long long totalTrips,long n,long long mid)
{
    long long sumtrips=totalTrips;
    for(int i=0;i<n;i++)
    {
        if(mid/time[i]>=sumtrips) return true;
        sumtrips-=mid/time[i];
    }
    return false;
}
// agar long long sahi jagah par nahi use kiya toh bhi tle aata hai aur search space bada hone se bhi tle aata hai.
class Solution {
public:
    long long minimumTime(vector<int>& time, long long totalTrips) {
  long long start=1;
  long long min=time[0];
  long n=time.size();
 for(long i=0;i<n;i++) 
 {
     if(min>time[i])
     {
         min=time[i];
     }
 }
 long long end=min*totalTrips;
 long long ans=-1;
 while(start<=end)
 {
     long long mid=start+(end-start)/2;
     if(isPossible(time,totalTrips,n,mid))
     {
         ans=mid;
         end=mid-1;
     }
     else start=mid+1;
 }
 return ans;
    }

};