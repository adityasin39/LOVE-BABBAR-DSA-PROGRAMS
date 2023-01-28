// Approach 1 TC- O(nlogn)
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for(int i=m,j=0;i<m+n;i++,j++)
//         {
//             nums1[i]=nums2[j];
//         }
//         sort(nums1.begin(),nums1.end());
//     }
// };
// 2nd approach totally stl Tc-O(nlogn)
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         nums1.erase(nums1.begin()+m,nums1.end());
//         for(auto it:nums2)
//         {
//             nums1.push_back(it);
//         }
//         sort(nums1.begin(),nums1.end());
//     }
// };
//3rd and the best Tc O(n) approach. if you dont understand then refer to https://www.youtube.com/watch?v=P1Ic85RarKY
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0)
        {
            nums1=nums2;
            return;
        }
        if(n==0) return;
        int i=m+n-1;
      int j=n-1;
      int k=m-1;
      while(j>=0)
      {
          if(k<0) nums1[i--]=nums2[j--];
         else if( nums1[k]<=nums2[j]) nums1[i--]=nums2[j--];
         else  nums1[i--]=nums1[k--];
           }
    }
};