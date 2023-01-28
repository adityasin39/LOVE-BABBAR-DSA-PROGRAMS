class Solution {
    int binarysearch(vector<int>& nums,int target,int start,int end)
{
    if(start>end) return -1;
    int mid=start+(end-start)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target)return binarysearch(nums,target,mid+1,end);
    else return binarysearch(nums,target,start,mid-1);
    
    
}
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int ans=binarysearch(nums,target,start,end);
        return ans;
    }
};