// jaha par bhi badi value store hone ka chance hai waha modulus lagana hoga.
// Aur typecast bhi karna hoga as % works on same datatype operands
class Solution {
  public:
  // TC=O(n) and SC=O(n)-stack space+O(n)-dp space
    long long int memo(int n, vector<long long int>& dp)
    {
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(memo(n-1,dp)+memo(n-2,dp))%(long long int)(1e9+7);
    }
    long long int topDown(int n) {
        vector<long long int> dp(n+1,-1);
        return (memo(n,dp))%(long long int)(1e9+7);
    }
    // TC=O(n) and SC=O(1)
    long long int bottomUp(int n) {
        long long int prev=1;
        long long int prev2=0;
        for(int i=2;i<=n;i++)
        {
            long long int cur=(prev+prev2)%(long long int)(1e9+7);
            prev2=prev;
            prev=cur;
        }
        return (prev)%(long long int)(1e9+7);
    }
};