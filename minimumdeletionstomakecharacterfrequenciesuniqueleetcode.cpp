// Iterate on the alphabet characters, keep decreasing the frequency of the current character until it reaches a value that has not appeared before.
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> characterToFreq;
        for(int i=0;i<s.size();i++) characterToFreq[s[i]]++;
        vector<int> freq;
        unordered_map<int,int> freqToFreq;
        for(auto it: characterToFreq) 
        {
            freq.push_back(it.second);
            freqToFreq[it.second]++;
        }
        int ans=0;
        for(int i=0;i<freq.size();i++)
        {
            if(freqToFreq[freq[i]]==1) continue;
            else
            {
                freqToFreq[freq[i]]--;
                while(freq[i]!=0)
                {
                    freq[i]--;
                    ans++;
                    if(freqToFreq[freq[i]]>=1) continue;
                    else break;
                }
                if(freq[i]!=0) freqToFreq[freq[i]]++; 
            }
        }
        return ans;
    }
};