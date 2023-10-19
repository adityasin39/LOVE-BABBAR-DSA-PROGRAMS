class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> subans;
            for(int j=1;j<=i;j++)
            {
                if(j==1 || j==i)
                {
                    subans.push_back(1);
                    continue;
                }
                subans.push_back(ans[i-2][j-2]+ans[i-2][j-1]);
            }
            ans.push_back(subans);
        }
        return ans;
    }
};