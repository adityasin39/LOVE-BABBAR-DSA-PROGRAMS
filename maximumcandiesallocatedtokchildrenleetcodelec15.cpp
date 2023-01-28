bool isPossible(vector<int>& candies, long long k,int n,int mid)
{
    long long childcount=1;
    for(int i=0;i<n;i++)
    {
     
     if(candies[i]>=mid)
     {
         int factor=candies[i]/mid;
         childcount+=factor;
         if(childcount>k) return true;
         continue;
     }
     else continue;    
    }
    return false;
}
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
         int start=1;
        long long n=candies.size();
        long long sum=0;
        for(int i=0;i<n;i++) sum+=candies[i];
        if(sum<k) return 0;
        int maxi=candies[0];
        for(int i=0;i<n;i++) 
        {
            if(maxi<candies[i])
            {
                maxi=candies[i];
            }
        }
        int end=maxi;
        int ans=0;

        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(candies,k,n,mid))
            {
                ans=mid;
                start=mid+1;

            }
            else end=mid-1;
        }
        return ans;
    }
};