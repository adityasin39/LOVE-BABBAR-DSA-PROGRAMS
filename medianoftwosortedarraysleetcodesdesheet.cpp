// if you dont understand then refer to striver video of this question
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int m=nums1.size();
      int n=nums2.size();
      if(m>n) return findMedianSortedArrays(nums2,nums1);
      int start=0;
      int end=m;
      int left=(m+n+1)/2;
      double ans=0;
      while(start<=end)
      {
          int mid1=start+(end-start)/2;
          int mid2=left-mid1;
          int l1=INT_MIN;
          int l2=INT_MIN;
          int r1=INT_MAX;
          int r2=INT_MAX;
          if(mid1!=0) l1=nums1[mid1-1];
          if(mid2!=0) l2=nums2[mid2-1];
          if(mid1!=m) r1=nums1[mid1];
          if(mid2!=n) r2=nums2[mid2];
          if(l1<=r2 && l2<=r1) 
          {
              if((m+n)%2)
              {
                 ans=max(l1,l2);
              }
              else
              {
                  ans=(max(l1,l2)+min(r1,r2))/2.0;
              }
              return ans;
          }
          else if(l1>r2) end=mid1-1;
          else start=mid1+1;
      } 
      return -1;
    }
};