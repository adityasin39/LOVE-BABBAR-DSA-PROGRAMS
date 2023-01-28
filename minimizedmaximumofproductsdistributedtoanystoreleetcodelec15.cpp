bool isPossible(int n, vector<int>& quantities,int m,int mid)
{
    int storecount=0;
    for(int i=0;i<m;i++)
    {
        if(mid==0) return false;
        double factor=quantities[i]/double(mid);
        int ceiling=ceil(factor);
        storecount+=ceiling;
        if(storecount>n) return false;

    }
    return true;
}
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int start=0;
        int maxi=quantities[0];
        for(int i=0;i<m;i++) maxi=max(maxi,quantities[i]);
        int end=maxi;
        int ans;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(n,quantities,m,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};