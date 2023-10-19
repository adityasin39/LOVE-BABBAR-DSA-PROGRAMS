// to solve the partitions independently, you need to sort the array.
// using recursion
// class Solution {
// public:
//     int solve(int i, int j, vector<int>& cuts) {
//         if (i > j) return 0;
//         int mini = 1e9;
//         for (int k = i; k <= j; k++) {
//             int cost = cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts)+solve(k+1,j,cuts);
//             mini = min(mini, cost);
//         }
//         return mini;
//     }
    
//     int minCost(int n, vector<int>& cuts) {
//         cuts.insert(cuts.begin(), 0);
//         cuts.push_back(n);
//         sort(cuts.begin(), cuts.end());
//         return solve(1, cuts.size() - 2, cuts);
//     }
// };
// using memoization
// class Solution {
// public:
//     int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
//         if (i > j) return 0;
//         int mini = 1e9;
//         if(dp[i][j]!=-1) return dp[i][j];
//         for (int k = i; k <= j; k++) {
//             int cost = cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
//             mini = min(mini, cost);
//         }
//         return dp[i][j]=mini;
//     }  
//     int minCost(int n, vector<int>& cuts) {
//         cuts.insert(cuts.begin(), 0);
//         cuts.push_back(n);
//         sort(cuts.begin(), cuts.end());
//         vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
//         return solve(1, cuts.size() - 2, cuts,dp);
//     }
// };
// using tabulation
class Solution {
public: 
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2,vector<int>(c+2,0)); // c+2 because we have j+1 where j can be c giving runtime error
        for(int i=c;i>=1;i--)
        {
            for(int j=i;j<=c;j++)
            {
                int mini=1e9;
                for(int k=i;k<=j;k++)
                {
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};