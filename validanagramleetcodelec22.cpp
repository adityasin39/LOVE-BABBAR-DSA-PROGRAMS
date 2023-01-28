class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()<t.size()|| s.size()>t.size()) return false;
        vector<int> hashs(26,0);
        vector<int> hasht(26,0);
        int i=0;
        while(i<s.size())
        {
            hashs[s[i]-'a']++;
            hasht[t[i]-'a']++;
            i++;
        }
        if(hashs==hasht) return true;
        return false;
    }
};