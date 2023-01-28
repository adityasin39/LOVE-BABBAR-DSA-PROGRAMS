bool isPossible(vector<int>& nums,int n,int mid)
{
    for(int i=0;i<n;i++)
    {
        if(nums[i]+nums[n-i-1]<=mid)
        {
            continue;
        }
        else return false;
    }
    return true;
}
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int start=nums[0]+nums[1];
        int end=nums[n-2]+nums[n-1];
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(nums,n,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};