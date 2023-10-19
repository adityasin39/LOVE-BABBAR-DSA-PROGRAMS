// the minor change from buy and sell stock 2 will be to deduct the fee either in the buy part or the sell part.
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> prev(2,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(2,0);
            for(int j=0;j<2;j++)
            {
                if(j==1)
                {
                    curr[j]=max(-prices[i]+prev[0],prev[1]);
                }
                else curr[j]=max(prices[i]-fee+prev[1],prev[0]);
            }
            prev=curr;
        }
        return prev[1]; 
    }
};