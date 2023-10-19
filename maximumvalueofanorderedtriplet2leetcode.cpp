class Solution {
public:
    int getmax(set<int>& st)
    {
        auto it=st.end();
        it--;
        return *it;
    }
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxSuffix(n+1);
        maxSuffix[n]=0;
        for(int i=n-1;i>=0;i--) maxSuffix[i]=max(nums[i],maxSuffix[i+1]);
        set<int> st;
        st.insert(nums[0]);
        long long ans=INT_MIN;
        for(int i=1;i<n-1;i++)
        {
            int first=getmax(st);
            ans = max(ans, (long long)first * maxSuffix[i+1] - (long long)nums[i] * maxSuffix[i+1]);
            st.insert(nums[i]);
        }
        if(ans<0) return 0;
        return ans;
    }
};