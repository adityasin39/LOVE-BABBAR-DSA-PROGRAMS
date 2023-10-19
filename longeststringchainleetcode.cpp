class Solution {
public:
 bool isPredecessor(string& s1, string& s2) {
    int i = 0;
    int j = 0;
    int m = s1.size();
    int n = s2.size();
    
    while (i < m && j < n) {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }
    
    return i == m;
}

    struct Op{
     bool operator()(string& s1, string& s2)
    {
        if(s1.size()>s2.size()) return false;
        return true;
    }
    };
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),Op());
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(words[i].size()==(words[j].size()+1) && isPredecessor(words[j],words[i]) && (1+dp[j])>dp[i]) dp[i]=1+dp[j];
            }
            if(dp[i]>maxi) maxi=dp[i];
        }
        return maxi;
    }
};