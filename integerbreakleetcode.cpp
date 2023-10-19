// if you dont understand then refer to neetcode video
// class Solution {
// public:
//     int integerBreak(int n) {
//         vector<int> dp(n+1,0);
//         if(n<=3) return n-1;
//         dp[1]=1;
//         for(int i=2;i<=n;i++)
//         {
//             int maxi=i;
//             for(int j=1;j<=i/2;j++) maxi=max(maxi,dp[j]*dp[i-j]);
//             dp[i]=maxi;
//         }
//         return dp[n];
//     }
// };
// if you dont understand then refer to leetcode editorial
class Solution {
public:
    int integerBreak(int n) {
      if(n<=3) return n-1;
      if(n%3==0) return pow(3,n/3);
      else if(n%3==1) return pow(3,n/3-1)*4;
      else return pow(3,n/3)*2;
    }
};