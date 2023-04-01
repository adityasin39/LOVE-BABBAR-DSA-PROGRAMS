#include<bits/stdc++.h>
using namespace std;
void solve(string str, vector<string> &ans, int index)
    {
        if(index>=str.size())
        {
            ans.push_back(str);
            return;
        }
        for(int j=index;j<str.size();j++)
        {
            swap(str[j],str[index]);
            solve(str,ans,index+1);
            swap(str[j],str[index]); // backtracking to make the nums as original for future answers
        }

    }
vector<string> generatePermutations(string &str)
{
      vector<string> ans;
       int index=0;
      solve(str,ans,index);
      sort(ans.begin(),ans.end());
      return ans;
}