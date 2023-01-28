class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       vector<int> ans;
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
       int i=0;
       int j=0;
       while(i<nums1.size() && j<nums2.size())
       {
           if(nums1[i]<nums2[j]) 
           {
                 while(i+1<nums1.size() && nums1[i]==nums1[i+1]) 
                 {
                   i++;
                 }
                 i++;
                 
           } 
           else if(nums1[i]>nums2[j])
           {
               while(j+1<nums2.size() && nums2[j]==nums2[j+1])
               {
                   j++;
               }
               j++;
           }
           else
           {
               ans.push_back(nums1[i]);
               while(i+1<nums1.size() && nums1[i]==nums1[i+1]) 
                 {
                   i++;
                 }
                 i++;
                 

           }

       
       }
       return ans; 
    }
};