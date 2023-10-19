// you can use stack as well
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> visited(26,0);
        vector<int> lastpos(26,-1);
        for(int i=0;i<s.size();i++) lastpos[s[i]-'a']=i;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(visited[s[i]-'a']==1) continue;
            else if(ans.size()==0)
            {
                ans+=s[i];
                visited[s[i]-'a']=1;
            }
            else
            {
                if(s[i]>ans.back())
                {
                    ans+=s[i];
                    visited[s[i]-'a']=1;
                }
                else
                {
                    while(ans.size()>0 && ans.back()>s[i])
                    {
                        if(lastpos[ans.back()-'a']>i)
                        {
                            visited[ans.back()-'a']=0;
                            ans.pop_back();
                        }
                        else break;
                    }
                    ans+=s[i];
                    visited[s[i]-'a']=1;
                }
            }
        }
        return ans;
    }
};