class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(p.size()>s.size()) return ans;
        vector<int> hashs(26,0);
        vector<int> hashp(26,0);
        int window=p.size();
        int left=0;
        int right=0;
        while(right<window)
        {
            hashs[s[right]-'a']++;
            hashp[p[right]-'a']++;
            right++;
        }
        right--;
        while(right<s.size())
        {
            if(hashs==hashp) ans.push_back(left);
            hashs[s[left]-'a']--;
            left++;
            right++;
            if(right<s.size()) hashs[s[right]-'a']++;
        }
        return ans;
    }
};  
