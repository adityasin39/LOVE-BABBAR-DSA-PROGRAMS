#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
      if(m>n) return ninjaAndLadoos(row2,row1,n,m,k);
      int start=0;
      int end=min(m,k);
      int left=k;
      int ans=0;
      while(start<=end)
      {
          int mid1=start+(end-start)/2;
          int mid2=left-mid1;
          if(mid2>n) 
          {
              start=mid1+1;
              continue;
          }
          int l1=INT_MIN;
          int l2=INT_MIN;
          int r1=INT_MAX;
          int r2=INT_MAX;
          if(mid1!=0) l1=row1[mid1-1];
          if(mid2!=0) l2=row2[mid2-1];
          if(mid1!=m) r1=row1[mid1];
          if(mid2!=n) r2=row2[mid2];
          if(l1<=r2 && l2<=r1) 
          {
           ans=max(l1,l2);
           return ans;
          }
          else if(l1>r2) end=mid1-1;
          else start=mid1+1;
      } 
      return -1;
}