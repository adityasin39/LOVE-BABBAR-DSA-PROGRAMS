// using memoization
// class Solution {
// public:
//     int getMax(int i, int j, vector<int>& arr)
//     {
//         int maxi=0;
//         for(int k=i;k<=j;k++) maxi=max(maxi,arr[k]);
//         return maxi;
//     }
//     int solve(int idx, int n, int k, vector<int>& arr, vector<int>& dp)
//     {
//         if(idx==n) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         int maxi=INT_MIN;
//         int sum=0;
//         for(int j=idx;j<idx+k;j++)
//         {
//             if(j<n){
//             int sum=getMax(idx,j,arr)*(j-idx+1);
//             int cost=sum+solve(j+1,n,k,arr,dp);
//             maxi=max(maxi,cost);
//             }
//         }
//         return dp[idx]=maxi;
//     }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n=arr.size();
//         vector<int> dp(n+1,-1);
//         return solve(0,n,k,arr,dp);
//     }
// };
// using tabulation
class Solution {
public:
    int getMax(int i, int j, vector<int>& arr)
    {
        int maxi=0;
        for(int k=i;k<=j;k++) maxi=max(maxi,arr[k]);
        return maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
                    int maxi=INT_MIN;
                    int sum=0;
        for(int j=i;j<i+k;j++)
        {
            if(j<n){
            int sum=getMax(i,j,arr)*(j-i+1);
            int cost=sum+dp[j+1];
            maxi=max(maxi,cost);
            }
        }
         dp[i]=maxi;
        }
        return dp[0];
    }
};