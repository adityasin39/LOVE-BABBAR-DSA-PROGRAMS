// isme mcm wala partition dp nahi lagega.
// here we use front partition ie. we call the recursion for only one function and move the index from the front
// we run a for loop to do partitions and then check if the string from i to j is a palindrome. If it is then we increase the cuts by 1 and call for the rest of the string.
// as the loop is going till n-1 so if the string from i to n-1 is a palindrome then it will count that partition too although there is no string ahead so the base case will be to return -1 on i==n so that unnecessary partition gets removed 
// class Solution {
// public:
//     bool isPalindrome(string& s, int i, int j)
//     {
//         while(i<j)
//         {
//             if(s[i]!=s[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
//     int solve(int idx, int n , string& s, vector<int>& dp)
//     {
//         if(idx==n) return -1;
//         if(dp[idx]!=-1) return dp[idx];
//         int mini=INT_MAX;
//         for(int j=idx;j<n;j++)
//         {
//             if(isPalindrome(s,idx,j)){
//             int cuts=1+solve(j+1,n,s,dp);
//             mini=min(mini,cuts);
//             }
//         }
//         return dp[idx]=mini;
//     }
//     int minCut(string s) {
//         int n=s.size();
//         if(isPalindrome(s,0,n-1)) return 0;
//         vector<int> dp(n+1,-1);
//         return solve(0,n,s,dp);
//     }
// };
// using tabulation
class Solution {
public:
    bool isPalindrome(string& s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n=s.size();
        if(isPalindrome(s,0,n-1)) return 0;
        vector<int> dp(n+1,-1);
        dp[n]=-1;
        for(int i=n-1;i>=0;i--)
        {
            int mini=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(isPalindrome(s,i,j)){
            int cuts=1+dp[j+1];
            mini=min(mini,cuts);
            }
        }
        dp[i]=mini;
        }
        return dp[0];
    }
};