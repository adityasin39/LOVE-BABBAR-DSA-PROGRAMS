class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target) return sum;
                if(abs(target-sum)<abs(target-closest)) closest=sum;
                if(sum>target)
                {
                   while(j<k && nums[k]==nums[k-1])
                   {
                       k--;
                   }
                   k--;
                }
                else
                {
                    while(j<k && nums[j]==nums[j+1])
                    {
                        j++;
                    }
                    j++;
                }
            }
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
          return closest;
    }
};