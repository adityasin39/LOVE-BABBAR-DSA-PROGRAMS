// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    string s="abcdabghabd";
    string t="ab#";
    int i=0;
    int j=0;
    int n=s.size();
    int m=t.size();
    vector<int> ans;
    int index=-1;
   while(i<n)
   {
       
       while(t[j]=='#' || s[i]==t[j])
       {
        if(i-1==0 || j-1==0 || s[i-1]!=t[j-1])  index=i+1;
           i++;
           j++;
       }
       if(j==m){
        j=0;
        ans.push_back(index);
        i--;
       }
       i++;
   }
   cout<<3;
   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}