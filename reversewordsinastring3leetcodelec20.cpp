class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        while(i<n)
        {
            while(j<=n-1 && s[j]!=' ' ) j++; // if the first condition is false then the second condition is not checked.
            reverse(s.begin()+i,s.begin()+j);
            i=j+1;
            j=i;
        }
        return s;
    }
};