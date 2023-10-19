class Solution {
public:
        void solve(int idx, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& subans)
    {
        if(target==0)
        {
            ans.push_back(subans);
            return;
        }
        if(target<0) return;
        for(int i=idx;i<candidates.size();i++)
        {
            subans.push_back(candidates[i]);
            solve(i,candidates,target-candidates[i],ans,subans);
            subans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subans;
        solve(0,candidates,target,ans,subans);
        return ans;
    }
};