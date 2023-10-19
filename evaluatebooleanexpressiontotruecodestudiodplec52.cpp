// using recursion
// #include <bits/stdc++.h> 
// int solve(int i, int j, int isTrue, string& exp)
// {
//     if(i==j)
//     {
//         if(isTrue) return exp[i]=='T';
//         else return exp[i]=='F';
//     }
//     int ways=0;
//     for(int k=i+1;k<j;k+=2)
//     {
//          if(exp[k]=='&')
//          {
//              if(isTrue) ways+= solve(i,k-1,1,exp)*solve(k+1,j,1,exp);
//            else ways+=solve(i,k-1,1,exp)*solve(k+1,j,0,exp)+ solve(i,k-1,0,exp)*solve(k+1,j,1,exp)+ solve(i,k-1,0,exp)*solve(k+1,j,0,exp);
//          }
//          if(exp[k]=='|')
//          {
//              if(isTrue) ways+=solve(i,k-1,1,exp)*solve(k+1,j,1,exp)+solve(i,k-1,1,exp)*solve(k+1,j,0,exp)+solve(i,k-1,0,exp)*solve(k+1,j,1,exp);
//              else ways+=solve(i,k-1,0,exp)*solve(k+1,j,0,exp);
//          }
//          if(exp[k]=='^')
//          {
//              if(isTrue) ways+=solve(i,k-1,1,exp)*solve(k+1,j,0,exp)+solve(i,k-1,0,exp)*solve(k+1,j,1,exp);
//              else ways+=solve(i,k-1,1,exp)*solve(k+1,j,1,exp)+solve(i,k-1,0,exp)*solve(k+1,j,0,exp);
//          }
//     }
//     return ways;
// }
// int evaluateExp(string & exp) {
//     int n=exp.size();
//    return solve(0,n-1,1,exp);
// }
// using memoization and also this code is better
// we are doing long long and modulo as in the question, it is mentioned that the ways can be very large.
// #define ll long long
// int mod = 1000000007;

// int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
//     //Base case:
//     if (i == j) {
//         if (isTrue == 1) return exp[i] == 'T';
//         else return exp[i] == 'F';
//     }

//     if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
//     ll ways = 0;
//     for (int ind = i + 1; ind <= j - 1; ind += 2) {
//         ll lT = f(i, ind - 1, 1, exp, dp);
//         ll lF = f(i, ind - 1, 0, exp, dp);
//         ll rT = f(ind + 1, j, 1, exp, dp);
//         ll rF = f(ind + 1, j, 0, exp, dp);

//         if (exp[ind] == '&') {
//             if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
//             else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
//         }
//         else if (exp[ind] == '|') {
//             if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
//             else ways = (ways + (lF * rF) % mod) % mod;
//         }
//         else {
//             if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
//             else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
//         }
//     }
//     return dp[i][j][isTrue] = ways;
// }
// int evaluateExp(string & exp) {
//     // Write your code here.
//     int n = exp.size();
//     vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
//     return f(0, n - 1, 1, exp, dp);
// }
// using tabulation
#include<bits/stdc++.h>
#define ll long long
int mod = 1000000007;
int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(i==j)
                {
                    if(k==1)
                    {
                       if(exp[i]=='T') dp[i][j][k]=1;
                       else dp[i][j][k]=0;
                    }
                    else{
                        if(exp[i]=='F') dp[i][j][k]=1;
                        else dp[i][j][k]=0;
                    }
                }
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=0;k<2;k++)
            {
                 ll ways = 0;
             for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = dp[i][ind - 1][1];
        ll lF = dp[i][ind - 1][0];
        ll rT = dp[ind + 1][j][1];
        ll rF = dp[ind + 1][j][0];

        if (exp[ind] == '&') {
            if (k) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (k) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {
            if (k) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
             }
    
          dp[i][j][k] = ways;
            }
        }
    }
   return dp[0][n-1][1];
} 