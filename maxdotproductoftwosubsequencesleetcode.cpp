// lcs variation
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp)
    {
        if(i==nums1.size() || j==nums2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j]; 
        int op1=nums1[i]*nums2[j]+solve(nums1,nums2,i+1,j+1,dp);
        int op2=solve(nums1,nums2,i+1,j,dp);
        int op3=solve(nums1,nums2,i,j+1,dp);
        return dp[i][j]=max(op1,max(op2,op3));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int max1=-10001;
        int max2=-10001;
        int min1=10001;
        int min2=10001;
        for(int i=0;i<nums1.size();i++) 
        {
            max1=max(max1,nums1[i]);
            min1=min(min1,nums1[i]);
        }
        for(int i=0;i<nums2.size();i++) 
        {
            max2=max(max2,nums2[i]);
            min2=min(min2,nums2[i]);
        }
        if(max1<0 && min2>0) return max1*min2;
        if(max2<0 && min1>0) return max2*min1;
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return solve(nums1,nums2,0,0,dp);
    }
};