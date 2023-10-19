//if you use set to avoid duplicates then you will get tle
// if you have a backtracking question and you have to do pick/notpick then use a for loop instead
class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& subans)
    {
        if(target==0)
        {
            ans.push_back(subans);
            return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(candidates[i]>target) return;
            if(i>0 && candidates[i]==candidates[i-1] && i>idx) continue;
            subans.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],ans,subans);
            subans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> subans;
        solve(0,candidates,target,ans,subans);
        return ans;
    }
};