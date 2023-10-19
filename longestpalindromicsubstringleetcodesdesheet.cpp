// Consider every element as the center of the palindrome and then expand to calculate the max length of the palindrome if the current element is considered to be the center.This is possible for odd length palindrome.
// For even length palindrome, just check if s[i]==s[i+1] and then continue the same process as done in the odd length palindrome case.
// This method checks if the substring is a palindrome while creating the substring on the fly. Thus, here the palindrome check is a O(1) operation.
class Solution {
public:
    void expand(int& left, int& right, string& s)
    {
        while((left-1)>=0 && ((right+1)<s.size()) && s[left-1]==s[right+1])
        {
            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        int maxlength=1;
        pair<int,int> ans;
        int n=s.size();
        for(int i=0;i<n-1;i++)
        {
            int oddleftbound=i;
            int oddrightbound=i;
            expand(oddleftbound,oddrightbound,s);
            int oddlength=oddrightbound-oddleftbound+1;
            if(oddlength>maxlength)
            {
                maxlength=oddlength;
                ans.first=oddleftbound;
                ans.second=oddrightbound;
            }
            if(s[i]==s[i+1])
            {
                int evenleftbound=i;
                int evenrightbound=i+1;
                expand(evenleftbound,evenrightbound,s);
                int evenlength=evenrightbound-evenleftbound+1;
                if(evenlength>maxlength)
                {
                    maxlength=evenlength;
                    ans.first=evenleftbound;
                    ans.second=evenrightbound;
                }
            }
        }
        string res="";
        auto it=ans;
        int start=it.first;
        int end=it.second;
        for(int i=start;i<=end;i++) res+=s[i];
        return res;
    }
};