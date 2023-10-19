//you cant use lcs tabulation here because consider the case when str1=bc and str2=cbccabcc. The string not matching condition will not work here. So we have to modify lcs tabulation in the not matching part.
//so we make a tabulation where dp[i][j] means the length of the longest common substring ending at i,j
// so we do dp[i][j]=0 in the not matching part and then the max value in the dp table will be our answer.
// agar 0 nahi karenge toh carry on ho jaaega aur wrong answer dega.
// if you dont understand then refer to striver notes of this lec
// the below recursion is different from tabulation
// using recursion
// #include <bits/stdc++.h> 
// int solve( string& str1, string& str2,int len1, int len2, int count)
// {
// 	    // Base case: if either string is empty, return the count
//     if (len1 == 0 || len2 == 0)
//         return count;

//     // If the last characters of the two strings match
//     if (str1[len1 - 1] == str2[len2 - 1]) {
//         count = solve(str1, str2, len1 - 1, len2 - 1, count + 1);
//     }

//     // Recursively find the longest common substring by considering
//     // substrings by excluding the last character of each string
//     count = std::max(count, std::max(solve(str1, str2, len1 - 1, len2, 0),
//                                       solve(str1, str2, len1, len2 - 1, 0)));

//     return count;
// }
// int lcs(string &str1, string &str2){
// 	int m=str1.size();
// 	int n=str2.size();
// 	return solve(str1,str2,m,n,0);
// }
//using tabulation
int lcs(string &str1, string &str2){
	int m=str1.size();
	int n=str2.size();
	int cnt=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++) dp[0][i]=0;
        for(int i=0;i<=m;i++) dp[i][0]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
              if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                cnt = max(cnt,dp[i][j]);
              } else
                dp[i][j] = 0;
            }
        }
	return cnt;
}