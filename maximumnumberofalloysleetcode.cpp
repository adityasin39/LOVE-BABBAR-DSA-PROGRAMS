// if you are not getting the end value then refer to pawan giri video or analyse yourself
class Solution {
public:
    bool isPossible(int mid, int n, int k, int budget, vector<vector<int>>& composition,vector<int>& stock, vector<int>& cost)
    {
        long long expense=INT_MAX;
        for(int i=0;i<k;i++)
        {
            long long extra=0;
            for(int j=0;j<n;j++)
            {
                long long total=(long long)composition[i][j]*mid;
                if(total<=stock[j]) continue;
                else
                {
                    extra+=(total-stock[j])*cost[j];
                }
            }
            expense=min(expense,extra);
        }
        return (expense<=budget);
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int start=0;
        int end=1e9;
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(mid,n,k,budget,composition,stock,cost))
            {
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
};