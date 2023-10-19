// |n-m|<=1 ka koi significance nahi hai, it will always be true
// we dont need k pointer so i have reduced 3d dp to 2d dp
class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j,vector<vector<int>>& dp)
    {
        if(i==s1.size())
        {
            if(s2.substr(j,s2.size()-j)==s3.substr(i+j,s3.size()-(i+j))) return true;
            else return false;
        }
        if(j==s2.size())
        {
            if(s1.substr(i,s1.size()-i)==s3.substr(i+j,s3.size()-(i+j))) return true;
            else return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool match1=false;
        bool match2=false;
        if(s1[i]==s3[i+j]) match1=solve(s1,s2,s3,i+1,j,dp); 
        if(s2[j]==s3[i+j]) match2=solve(s1,s2,s3,i,j+1,dp);
        return dp[i][j]=match1 || match2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,s3,0,0,dp);
    }
};