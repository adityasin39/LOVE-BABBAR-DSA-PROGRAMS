#include <bits/stdc++.h>
//Approach 1
//Two pointer approach.
// if you dont understand then refer to solution tab approach 3
vector<vector<int>> pairSum(vector<int> &arr, int s){
   unordered_map<int,int> mp;
   vector<vector<int>> ans;
   for(int i=0;i<arr.size();i++) mp[arr[i]]++;
   vector<int> keyArray;
   for(auto it:mp)
   {
       keyArray.push_back(it.first);
   }
   sort(keyArray.begin(),keyArray.end());
   for(int i=0;i<keyArray.size();i++)
   {
       if(keyArray[i]+keyArray[i]==s){
       int freq=mp[keyArray[i]];
       for(int j=0;j<freq*(freq-1)/2;j++)
       {
           vector<int> subans;
           subans.push_back(keyArray[i]);
           subans.push_back(keyArray[i]);
           ans.push_back(subans);
       }
       }
   }
   int low=0;
   int high=keyArray.size()-1;
   while(low<high)
   {
       if(keyArray[low]+keyArray[high]==s)
       {
           for(int i=0;i<mp[keyArray[low]]*mp[keyArray[high]];i++)
           {
               vector<int> subans;
               subans.push_back(keyArray[low]);
               subans.push_back(keyArray[high]);
               ans.push_back(subans);
           }
           low++;
           high--;
           
       }
       else if(keyArray[low]+keyArray[high]<s) low++;
       else high--;
   }
   sort(ans.begin(),ans.end());
   return ans;
}
//Approach 2 using only map, for this solution refer to solution tab approach 2
//Approach 3 using multimap, this is similar to approach 2
// find,count,insertion/deletion takes logn time so here TC=O(nlogn)
//    vector<vector<int>> ans;
//    multimap<int,int> mp;
        
//         for(int i=0;i<arr.size();i++)
//         {
//             vector<int> subans;
//             if(mp.count(s-arr[i]))
//             {
//               int a=arr[i];
//               int b=s-arr[i];
//               int cnt=mp.count(s-arr[i]);
//               while (cnt) {
//                 subans.push_back(min(a, b));
//                 subans.push_back(s - min(a, b));
//                 ans.push_back(subans);
//                 cnt--;
//               }
//             }
//             mp.insert({arr[i],i});
//         }
//         sort(ans.begin(),ans.end());
//         return ans;
// }