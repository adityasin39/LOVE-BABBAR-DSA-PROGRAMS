bool isPossible(vector<int>& weights, int days,int n,int mid)
{
    int daycount=1;
    int lastpos=0;
    for(int i=0;i<n;i++)
    {
        if(lastpos+weights[i]<=mid)
        {
            
            lastpos+=weights[i];

        }
        else
        {
            daycount++;
            if(daycount>days || weights[i]>mid) return false;
            lastpos=weights[i];
        }

    }
    return true;
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start=0;
        int n=weights.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=weights[i];
        int end=sum;
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(weights,days,n,mid))
            {
                ans=mid;
                end=mid-1;

            }
            else start=mid+1;
        }
        return ans;
    }
};