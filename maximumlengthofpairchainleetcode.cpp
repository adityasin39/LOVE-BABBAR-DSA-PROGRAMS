class Solution {
public:
    struct comp
    {
        bool operator()(vector<int> interval1, vector<int> interval2)
        {
            return interval1[1]<interval2[1];
        }
    };
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp());
        int last=pairs[0][1];
        int cnt=1;
        for(int i=1;i<pairs.size();i++)
        {
            if(pairs[i][0]>last)
            {
                last=pairs[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};