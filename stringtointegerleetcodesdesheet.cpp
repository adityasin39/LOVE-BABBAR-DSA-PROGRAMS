class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' ') i++;
        if(i==n) return 0;
        char sign='+';
        if(s[i]=='+' || s[i]=='-') sign=s[i++];
        int ans=0;
        while(i<n && s[i]>='0' && s[i]<='9')
        {
            if(ans>INT_MAX/10 && sign=='+') return INT_MAX;
            if(ans>INT_MAX/10 && sign=='-') return INT_MIN;
            if(ans*10>INT_MAX-(s[i]-'0'))
            {
                if(sign=='+') return INT_MAX;
                return INT_MIN;
            }
            ans=ans*10+(s[i++]-'0');
        }
        if(ans==0) return 0;
        return (sign=='+'?ans:-ans);
    }
};