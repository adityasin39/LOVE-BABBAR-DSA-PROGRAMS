class Solution {
public:
    void solve(int idx, int k, int size, int n, vector<int>& subans, vector<vector<int>>& ans, vector<int>& arr)
    {
        if(n==0 && size==k)
        {
            ans.push_back(subans);
            return;
        }
        if(n==0 || size==k) return;
        for(int i=idx;i<arr.size();i++)
        {
            subans.push_back(arr[i]);
            solve(i+1,k,size+1,n-arr[i],subans,ans,arr);
            subans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subans;
        vector<int> arr;
        for(int i=1;i<=9;i++) arr.push_back(i);
        solve(0,k,0,n,subans,ans,arr);
        return ans;
    }
};