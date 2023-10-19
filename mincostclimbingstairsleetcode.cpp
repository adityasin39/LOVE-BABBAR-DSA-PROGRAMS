class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int next1=0;
        int next2=0;
        int curr=0;
        for(int i=cost.size()-1;i>=0;i--)
        {
            int op1=cost[i]+next1;
            int op2=cost[i]+next2;
            curr=min(op1,op2);
            next2=next1;
            next1=curr;
        }
        return min(next1,next2);
    }
};