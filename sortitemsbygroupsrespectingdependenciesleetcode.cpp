// if you dont understand then refer to the leetcode editorial
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<group.size();i++)
        {
            if(group[i]==-1)
            {
                group[i]=m;
                m++;
            }
        }
        vector<int> adjItems[n];
        vector<int> adjGroups[m];
        vector<int> indegreeItems(n,0);
        vector<int> indegreeGroups(m,0);
        for(int i=0;i<beforeItems.size();i++)
        {
            for(int j=0;j<beforeItems[i].size();j++)
            {
                if(group[i]==group[beforeItems[i][j]])
                {
                    adjItems[beforeItems[i][j]].push_back(i);
                    indegreeItems[i]++;
                }
                else
                {
                    adjGroups[group[beforeItems[i][j]]].push_back(group[i]);
                    indegreeGroups[group[i]]++;
                }
            }
        }
        queue<int> q1;
        for(int i=0;i<n;i++)
        {
            if(indegreeItems[i]==0) q1.push(i);
        }
        vector<int> topo1;
        while(!q1.empty())
        {
           int item=q1.front();
           q1.pop();
           topo1.push_back(item);
           for(auto it:adjItems[item])
           {
               indegreeItems[it]--;
               if(indegreeItems[it]==0) q1.push(it);
           }
        }
        if(topo1.size()!=n) return {};
        queue<int> q2;
        for(int i=0;i<m;i++)
        {
            if(indegreeGroups[i]==0) q2.push(i);
        }
        vector<int> topo2;
        while(!q2.empty())
        {
           int group=q2.front();
           q2.pop();
           topo2.push_back(group);
           for(auto it:adjGroups[group])
           {
               indegreeGroups[it]--;
               if(indegreeGroups[it]==0) q2.push(it);
           }
        }
        if(topo2.size()!=m) return {};
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<topo1.size();i++)
        {
            mp[group[topo1[i]]].push_back(topo1[i]);
        }
        vector<int> ans;
        for(int i=0;i<topo2.size();i++)
        {
            for(int j=0;j<mp[topo2[i]].size();j++)
            {
                ans.push_back(mp[topo2[i]][j]);
            }
        }
        return ans;
    }
};