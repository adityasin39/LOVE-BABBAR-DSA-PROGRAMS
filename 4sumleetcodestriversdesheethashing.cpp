class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //Best approach TC=O(n^3) and SC=O(no.of quads) for storing the answer otherwise O(1)
        //Here the complexity will be same as better approach but we have gotten rid of sets here. Here to get in sorted form we are sorting the array beforehand and to get unique quads we always skip duplicate numbers.
        //We use two pointers then
    //  vector<vector<int>> ans;
    //  sort(nums.begin(),nums.end());
    //  for(int i=0;i<nums.size();i++)
    //  {
    //      if(i>0 && nums[i]==nums[i-1]) continue;
    //      for(int j=i+1;j<nums.size();j++)
    //      {
    //          if(j>i+1 && nums[j]==nums[j-1]) continue;
    //          long long sum=nums[i]+nums[j];
    //          int k=j+1;
    //          int l=nums.size()-1;
    //          while(k<l)
    //          {
    //              long long subsum=nums[k]+nums[l];
    //              long long totalsum=subsum;
    //              totalsum+=sum;
    //              if(totalsum==target)
    //              {
    //                  vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
    //                  ans.push_back(temp);
    //                   l--;
    //                  while(l>0 && nums[l]==nums[l+1]) l--;
    //                         k++;
    //                  while(k<nums.size() && nums[k]==nums[k-1]) k++;

    //              }
    //              else if(totalsum>target)
    //              {
    //                  l--;
    //                  while(l>0 && nums[l]==nums[l+1]) l--;
    //              }
    //              else 
    //              {
    //                  k++;
    //                  while(k<nums.size() && nums[k]==nums[k-1]) k++;
    //              }
    //          }

    //      }
    //  }
    //    return ans;
    //Better approach similar to 2 sum problem hashing approach
    // if you dont understand then refer to strivers website solution approach 2
    // TC=O(n^3) and SC=O(no.of quads)*2+O(n)
        int n = nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<long long> s;// long long is important here for large integers
                for (int k = j + 1; k < n; k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth=target-sum;
                    if (s.find(fourth) != s.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k],int(fourth)};//typecasted to int
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    } else
                    {
                        s.insert(nums[k]);
                    }
                    
                }
            }
        }

        for (auto it : st) {
            ans.push_back(it);
        }
        return ans;
 

        //Brute force TC=O(n^4) SC=O(no. of quads*2) will give Tle
        // Here we have first tried to get all the possible quads and then checked if sum=target then we have sorted the vector so that whenever we get same quad then we will be able to identify that both are same and hence used a set so that we can push a unique quad always.
        // int n=nums.size();
        // set<vector<int>> st;// unordered set gives error
        // vector<vector<int>> ans;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         for(int k=j+1;k<n;k++)
        //         {
        //             for(int l=k+1;l<n;l++)
        //             {
        //                 long long sum=nums[i]+nums[j];// writing in different lines avoids overflow.
        //                 sum+=nums[k];
        //                 sum+=nums[l];
        //                 if(sum==target)
        //                 {
        //                     vector<int> temp={nums[i],nums[j],nums[k],nums[l]};// to push directly and this takes constant space as there are only 4 elements.
        //                     sort(temp.begin(),temp.end());// here sorting takes constant time as the number of elements in temp will always be 4
        //                     st.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // for(auto it:st)
        // {
        //     ans.push_back(it);
        // }
        // return ans;
    }
};