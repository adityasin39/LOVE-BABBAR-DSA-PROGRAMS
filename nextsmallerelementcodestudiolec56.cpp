// there are 4 type of variations 
// 1. next smaller element -> last se chalu karenge loop
// 2. next greater element -> last se chalu karenge
// 3. previous smaller element -> starting se chalu karenge loop
// 4. previous greater element -> starting se chalu karenge loop
// stack soln -> O(n)
// stack soln
#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    stack<int> st;
   for(int i=arr.size()-1;i>=0;i--)
   {
       while(st.empty()==0 && st.top()>=arr[i]) st.pop();
       if(st.empty()==0 && st.top()<arr[i]) ans.push_back(st.top());
       if(st.empty()) ans.push_back(-1);
       st.push(arr[i]);
   }
   reverse(ans.begin(),ans.end());
   return ans;
}
// brute force which gives tle
// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//     vector<int> ans;
//     for(int i=0;i<arr.size();i++)
//     {
//         bool found=false;
//         for(int j=i+1;j<arr.size();j++)
//         {
//             if(arr[j]<arr[i])
//             {
//                 found=true;
//                 ans.push_back(arr[j]);
//                 break;
//             }
//         }
//         if(found==false) ans.push_back(-1);

//     }
//     return ans;

// }