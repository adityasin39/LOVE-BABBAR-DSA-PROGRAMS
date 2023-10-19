class Solution {
public:
    int minimumOperations(string num) {
        bool zerofound=false;
        bool fivefound=false;
        int n=num.size();
        for(int i=n-1;i>=0;i--)
        {
            if(zerofound && num[i]=='5') return (n-i-2);
            if(zerofound && num[i]=='0') return (n-i-2);
            if(fivefound && num[i]=='2') return (n-i-2);
            if(fivefound && num[i]=='7') return (n-i-2);
            if(num[i]=='0') zerofound=true;
            if(num[i]=='5') fivefound=true;
        }
        if(zerofound) return (n-1);
        return n;
    }
};