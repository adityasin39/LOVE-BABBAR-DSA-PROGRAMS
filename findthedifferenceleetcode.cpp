class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        for(auto it: s) ans^=int(it);
        for(auto it: t) ans^=int(it);
        return (char)ans;
    }
};