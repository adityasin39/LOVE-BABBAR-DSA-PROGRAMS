 // using recursion
//   int solve(vector<int>& height, int n, int k, int minEnergy)
//   {
//       if(n==0) return 0;
//       for(int i=1;i<=k;i++)
//       {
//           if(n-i>=0)
//           {
//              int jump= solve(height,n-i,k,minEnergy)+abs(height[n]-height[n-i]);
//              minEnergy=min(minEnergy,jump);
//           }
//           else break;
//       }
//     return minEnergy;
//   }
//     int minimizeCost(vector<int>& height, int n, int k) {
//         int minEnergy=INT_MAX;
//         return solve(height,n-1,k,minEnergy);
//     }
// using memoization
// int solve(vector<int>& height, int n, int k, int minEnergy, vector<int>& dp)
//   {
//       if(n==0) return 0;
//       if(dp[n]!=-1) return dp[n];
//       for(int i=1;i<=k;i++)
//       {
//           if(n-i>=0)
//           {
//              int jump= solve(height,n-i,k,minEnergy,dp)+abs(height[n]-height[n-i]);
//              minEnergy=min(minEnergy,jump);
//           }
//           else break;
//       }
//       return dp[n]=minEnergy;
//   }
//     int minimizeCost(vector<int>& height, int n, int k) {
//         vector<int> dp(n,-1);
//         int minEnergy=INT_MAX;
//         return solve(height,n-1,k,minEnergy,dp);
//     }
// };
// using tabulation
    int minimizeCost(vector<int>& height, int n, int k) {
      vector<int> dp(n,-1);
      dp[0]=0;
     
      for(int i=1;i<n;i++)
      {
           int minEnergy=INT_MAX;
          for(int j=1;j<=k;j++)
          {
              if(i-j>=0)
              {
                  int jump=dp[i-j]+abs(height[i]-height[i-j]);
                  minEnergy=min(minEnergy,jump);
              }
              else break;
          }
          dp[i]=minEnergy;
      }
      return dp[n-1];
    }
};
// u cant optimize space here as k can be n too so it becomes the same thing