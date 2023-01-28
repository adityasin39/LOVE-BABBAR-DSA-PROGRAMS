class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<vector<int>> res;
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
       vector<int> tempc;
       vector<int> tempd;
     if(ans.size()==0)
     {
         for(int i=0;i<nums1.size();i++)
         {
             if(find(tempc.begin(),tempc.end(),nums1[i])==tempc.end())
             {
                 tempc.push_back(nums1[i]);
             }
         }
          for(int i=0;i<nums2.size();i++)
         {
             if(find(tempd.begin(),tempd.end(),nums2[i])==tempd.end())
             {
                 tempd.push_back(nums2[i]);
             }
         }
          res.push_back(tempc);
          res.push_back(tempd);

     }
     else
     {

     
       int a;
       int b;
           vector<int> tempa;
           for(a=0;a<nums1.size();a++)
           {
               for( b=0;b<ans.size();b++)
               {
                   if(nums1[a]==ans[b] )
                   {
                       break;
                   }
                   

                   
               }
            
               if(b==ans.size()&& find(tempa.begin(),tempa.end(),nums1[a])==tempa.end() )
               {
                      tempa.push_back(nums1[a]);


               }

           }
           int c,d;
           vector<int> tempb;
                  for( c=0;c<nums2.size();c++)
           {
               for( d=0;d<ans.size();d++)
               {
                   if(nums2[c]==ans[d] )
                   {
                       break;
                    
                   }
                   

                   
               }
               if(d==ans.size() && find(tempb.begin(),tempb.end(),nums2[c])==tempb.end())
               {
                      tempb.push_back(nums2[c]);

               }

           }
           res.push_back(tempa);
           res.push_back(tempb);
     }
       return res;
     
    }
    
};