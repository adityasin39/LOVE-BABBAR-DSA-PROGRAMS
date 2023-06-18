#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
     int n=v.size();
		    vector<vector<int>> ans;
       for(int i=0;i<(1<<n);i++) // 1<<n=2^n
       {
           vector<int> sub;
         for(int j=n-1;j>=0;j--) // as it needs in sorted form so started the loop from left
         {
             if(i&(1<<j)) sub.push_back(v[n-j-1]);
         }
          ans.push_back(sub);
       }
       return ans;
}