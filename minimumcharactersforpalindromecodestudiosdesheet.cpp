// O(2*n) kmp approach
#include<bits/stdc++.h>
void longestprefixsuffix(vector<int>& lps, string& b, int n)
    {
        int len=0;
        int i=1;
        lps[0]=0;
        while(i<n)
        {
            if(b[i]==b[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i]=0;
                    i++;
                }
                else len=lps[len-1];
            }
        }
    }
    int minCharsforPalindrome(string str) {
	string temp=str;
	reverse(temp.begin(),temp.end());
	string final=str+"$"+temp; // '$' is necessary so that the prefix doesnt cross the original string and the suffix doesnt cross the reversed string
	vector<int> lps(final.size(),0);
	longestprefixsuffix(lps, final, final.size());
	int ans=str.size()-lps[lps.size()-1]; // answer last mein reside karega kyonki pura string cover karna hai
	return ans;
}
// on observing a lot, you will realize that you need to find the length of the longest prefix which is also a suffix of the reversed string
// which gives the hint for kmp
// the below code is O(n^2)
// int minCharsforPalindrome(string str) {
// 	string temp=str;
// 	reverse(temp.begin(),temp.end()); //O(n)
// 	string a="";
// 	string b="";
// 	int index=-1;
// 	for(int i=0;i<str.size();i++)
// 	{
// 		a=temp[str.size()-i-1]+a; //O(n)
// 		b=b+str[i]; //O(n)
// 		if(a==b) index=i; //O(n)
// 	}
// 	int ans=str.size()-1-index;
// 	return ans;
// }
