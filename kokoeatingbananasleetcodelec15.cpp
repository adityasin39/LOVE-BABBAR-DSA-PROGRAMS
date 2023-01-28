bool isPossible(vector<int>& piles, long long h, long long n, long long mid)
{
    long long hourcount=0;
    for(long long i=0;i<n;i++)
    {
        if(mid>=piles[i])
        {
            hourcount++;
            if(hourcount>h) return false;
        }
        else
        {
            if(mid==0) return false;
            double factor=piles[i]/double(mid);
            int f=piles[i]/mid;
            if(f!=factor) hourcount+=f+1;
            else hourcount+=f;
            // long  int ceiling=ceil(factor);
            // hourcount+=ceiling;
            if(hourcount>h) return false;
        //    int leftbananas=piles[i];
        //    while(leftbananas)
        //    {
        //     leftbananas=leftbananas-mid;
        //     hourcount++;
        //     if(hourcount>h) return false;
        //     if(mid>=leftbananas){
        //         leftbananas=0; 
        //         hourcount++;
        //         if(hourcount>h) return false;
            
        //     }
        //    }
        }

    }
    return true;
}
class Solution {
public:
    long long minEatingSpeed(vector<int>& piles, long long h) {
        long long n=piles.size();
        long long maxi=piles[0];
        
        for(long long i=0;i<n;i++)
        {
            if(maxi<piles[i]) maxi=piles[i];
        }
        
        long long start=0;
        long long end=maxi;
        long long  ans=0;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(isPossible(piles,h,n,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};