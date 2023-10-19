// storing the whole string gives mle so think something of mod
// if you dont understand then refer to mohamedmamdouh solution
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long length=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z') length++;
            else length*=s[i]-'0';
        }
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                if(k==0 || length==k) return string("")+s[i];
                length--;
            }
            else
            {
                length/=s[i]-'0';
                k=k%length;
            }
        }
        return "";
    }
};