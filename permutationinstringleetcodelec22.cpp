// sliding window technique
// agar nahi samajh aaye toh refer techdose video.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(s1.size()>s2.size()) return false;
        vector<int> hashs1(26,0);
        vector<int> hashs2(26,0);
        int window=s1.size();
        int left=0;
        int right=0;
        while(right<window)
        {
            hashs1[s1[right]-'a']++;
            hashs2[s2[right]-'a']++;
            right++;
        }
        right--;
        while(right<s2.size())
        {
            if(hashs1==hashs2) return true;
            hashs2[s2[left]-'a']--;
            left++;
            right++;
            if(right<s2.size()) hashs2[s2[right]-'a']++;
        }
        return false;
    }
};