bool isPossible(vector<int>& nums, int threshold,int n,int mid)
{
    int division=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(mid==0) return false;
       division=ceil(nums[i]/float(mid));
       sum+=division;
       if(sum>threshold) return false;
    }
    return true;
}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1;
        int n =nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++)
        {
            if(maxi<nums[i])
            {
                maxi=nums[i];
            }
        }
        int end=maxi;
        int ans;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(nums,threshold,n,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};