class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int groups=n/3;
        int j=n-1;
        int ans=0;
        int cnt=0;
            while(cnt<groups)
            {
                ans+=cost[j];
                ans+=cost[j-1];
                j-=3;
                cnt++;
            }
            while(j>=0)
            {
                ans+=cost[j];
                j--;
            }
            return ans;
        
    }
};