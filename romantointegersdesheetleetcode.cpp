class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romanToint;
        romanToint['I']=1;
        romanToint['V']=5;
        romanToint['X']=10;
        romanToint['L']=50;
        romanToint['C']=100;
        romanToint['D']=500;
        romanToint['M']=1000;
        int i=0;
        int ans=0;
        while(i+1<s.size())
        {
            if(romanToint[s[i]]>=romanToint[s[i+1]])
            {
                ans+=romanToint[s[i]];
                i++;
            }
            else
            {
                ans+=romanToint[s[i+1]]-romanToint[s[i]];
                i+=2;
            }
        }
        if(i==s.size()-1) ans+=romanToint[s[i]];
        return ans;
    }
};