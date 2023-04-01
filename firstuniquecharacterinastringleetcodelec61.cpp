// best approach
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> mp;
        int idx=s.size();
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]].first++;
            mp[s[i]].second=i;
        }
        bool found=false;
        for(auto it: mp)
        {
            if(it.second.first==1)
            {
                found=true;
                idx=min(idx,it.second.second); // because the map is unordered
            }
        }
        if(found==false)
        return -1;
        return idx;
    }
};
// queue approach
//class Solution {
// public:
//     int firstUniqChar(string s) {
//         queue<int> q;
//         vector<int> count(26,0);
//         for(int i=0;i<s.size();i++) {
//         count[s[i]-'a']++;
//         q.push(i);
//         }
        
//         while(!q.empty() && count[s[q.front()]-'a']>1) q.pop();
//         if(q.empty()) return -1;
//         else return q.front();
        
//     }
// };