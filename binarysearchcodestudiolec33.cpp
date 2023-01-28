    int search(int nums[],int target,int start,int end)
{
    if(start>end) return -1;
    int mid=start+(end-start)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target)return search(nums,target,mid+1,end);
    else return search(nums,target,start,mid-1);
    
    
}
int binarySearch(int *input, int n, int val)
{
       int start=0;
       int end=n-1;
       int ans=search(input,val,start,end);
       return ans;
}