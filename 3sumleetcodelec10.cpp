// // 3 sum tle brute force
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> ans;
//         set<vector<int>> visited;
//         for(int i=0;i<n-2;i++)
//         {
//             for(int j=i+1;j<n-1;j++)
//             {
//                 for(int k=j+1;k<n;k++)
//                 {
//                     if(nums[i]+nums[j]+nums[k]==0)
//                     {
//                         vector<int> temp;
//                         temp.push_back(nums[i]);
//                         temp.push_back(nums[j]);
//                         temp.push_back(nums[k]);
//                         sort(temp.begin(),temp.end());
//                         if(visited.find(temp)==visited.end())
//                         {
//                             ans.push_back(temp);
//                             visited.insert(temp);
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int target=0-nums[i];
            int front=i+1;
            int back=n-1;
            while(front<back)
            {
                int sum=nums[front]+nums[back];
                if(sum>target)
                {
                    while(front<back && nums[back]==nums[back-1] )
                    {
                        back--;
                    }
                    back--;
                }
                else if(sum<target)
                {
                    while(front<back && nums[front]==nums[front+1])
                    {
                        front++;

                    }
                    front++;
                }
                    else
                    {
                        int x= nums[front];
                        int y=nums[back];
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[front]);
                        temp.push_back(nums[back]);
                        
                    
                        ans.push_back(temp);
                            
                        while(front < back && nums[front]==x)
                        {
                            front++;
                        }
                        while(front<back && nums[back]==y)
                        {
                            back--;
                        }
                    }
                }

            
            while(i+1 <n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};