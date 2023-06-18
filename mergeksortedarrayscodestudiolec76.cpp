// TC=O(n*klogk) 
#include <bits/stdc++.h> 
class Info
{
    public:
    int val;
    int i;
    int j;
    Info(int val, int row, int col)
    {
        this->val=val;
        i=row;
        j=col;
    }
};
struct comp {
    bool operator()(const Info& a, const Info& b) const {
        return a.val > b.val;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Info,vector<Info>,comp> minHeap;
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        Info temp(kArrays[i][0],i,0);
        minHeap.push(temp);
    }
    while(!minHeap.empty())
    {
        Info temp=minHeap.top();
        minHeap.pop();
        ans.push_back(temp.val);
        int nexti=temp.i;
        int nextj=temp.j+1;
        if(nextj<kArrays[temp.i].size())
        {
            Info next(kArrays[nexti][nextj],nexti,nextj);
            minHeap.push(next);
        }
    }
    return ans;

}
