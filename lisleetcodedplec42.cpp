//using recursion
// class Solution {
// public:
//     int solve(int n, int greater_index, vector<int>& nums, int length)
//     {
//         if(n==length) return 0;
//         int pick=INT_MIN;
//         if( greater_index==-1 || nums[n]>nums[greater_index])
//         {
//             pick=1+solve(n+1,n,nums,length);
//         }
//         int notpick=solve(n+1,greater_index,nums,length);
//         return max(pick,notpick);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         int greater_index=-1;
//         return solve(0,greater_index,nums,n);
//     }
// };
// using memoization
// memoization karne ke liye greater_index ki shifting ki hai.
// class Solution {
// public:
//     int solve(int n, int greater_index, vector<int>& nums, int length, vector<vector<int>>& dp)
//     {
//         if(n==length) return 0;
//         if(dp[n][greater_index+1]!=-1) return dp[n][greater_index+1];
//         int pick=INT_MIN;
//         if( greater_index==-1 || nums[n]>nums[greater_index])
//         {
//             pick=1+solve(n+1,n,nums,length,dp);
//         }
//         int notpick=solve(n+1,greater_index,nums,length,dp);
//         return dp[n][greater_index+1]=max(pick,notpick);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         int greater_index=-1;
//         return solve(0,greater_index,nums,n,dp);
//     }
// };
// using tabulation
// have done index shifting for greater_index
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//         for(int i=0;i<=n;i++) dp[n][i]=0;
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int j=i+1;j>=0;j--) // as we know that for each i initially we take greter_index as -1 in case of recursion so here as we are going opposite so i+1
//             {
//                 int pick=INT_MIN;
//                 if(j-1==-1 || nums[i]>nums[j-1]) pick=1+dp[i+1][i+1];
//                 int notpick=dp[i+1][j];
//                 dp[i][j]=max(pick,notpick);
//             }
//         }
//         return dp[0][0];
//     }
// };
// using space optimization
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> prev(n+1,0);
//         for(int i=0;i<=n;i++) prev[i]=0;
//         for(int i=n-1;i>=0;i--)
//         {
//             vector<int> curr(n+1,0);
//             for(int j=i+1;j>=0;j--) // as we know that for each i initially we take greter_index as -1 in case of recursion so here as we are going opposite so i+1
//             {
//                 int pick=INT_MIN;
//                 if(j-1==-1 || nums[i]>nums[j-1]) pick=1+prev[i+1];
//                 int notpick=prev[j];
//                 curr[j]=max(pick,notpick);
//             }
//             prev=curr;
//         }
//         return prev[0];
//     }
// };
// 2nd approach which is better and necessary to print the lis
// here i have found lis as well as printed it.
// see the code, if you dont understand then refer to striver notes of this lec
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,1);
    vector<int> hash(n);
    for(int i=0;i<n;i++) hash[i]=i;
    int maxi=0;
    int lis_index=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                if(1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
        }
        if(dp[i]>maxi)
        {
            maxi=dp[i];
            lis_index=i;
        }
    }
    int i=lis_index;
    vector<int> lis;
    while(hash[i]!=i)
    {
        lis.push_back(nums[i]);
        i=hash[i];
    }
    lis.push_back(nums[i]);
    reverse(lis.begin(),lis.end());
    for(auto it: lis) cout<<it<<" ";// printed the lis
    return maxi;
    }
};