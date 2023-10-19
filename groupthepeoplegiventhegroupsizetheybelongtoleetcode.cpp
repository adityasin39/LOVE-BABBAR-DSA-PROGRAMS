class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> groups;
        for(int i=0;i<groupSizes.size();i++)
        {
            groups[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto it: groups)
        {
            int members=it.second.size();
            int grps=members/(it.first);
            int j=0;
            while(grps--)
            {
                vector<int> temp;
               for(int i=0;i<it.first;i++)
               {
                   temp.push_back(it.second[j]);
                   j++;
               }
               ans.push_back(temp);
            }
        }
        return ans;
    }
};