/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        vector<int> arr(n,-1);
        int start=0;
        int end=n-1;
        int peakIndex=-1;
        int peak=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid==0)
            {
                start=mid+1;
                continue;
            }
            if(mid==n-1)
            {
                end=mid-1;
                continue;
            }
            if(arr[mid]==-1) arr[mid]=mountainArr.get(mid);
            if(arr[mid-1]==-1) arr[mid-1]=mountainArr.get(mid-1);
            if(arr[mid+1]==-1) arr[mid+1]=mountainArr.get(mid+1);
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
            {
                peakIndex=mid;
                peak=arr[mid];
                break;
            }
            else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]) start=mid+1;
            else end=mid-1;
        }
        if(peak==target) return peakIndex;
        int leftstart=0;
        int leftend=peakIndex-1;
        int rightstart=peakIndex+1;
        int rightend=n-1;
        if(arr[leftstart]==-1) arr[leftstart]=mountainArr.get(leftstart);
        if(arr[leftend]==-1) arr[leftend]=mountainArr.get(leftend);
        if(arr[rightstart]==-1) arr[rightstart]=mountainArr.get(rightstart);
        if(arr[rightend]==-1) arr[rightend]=mountainArr.get(rightend);
        if(target>=arr[leftstart] && target<=arr[leftend])
        {
            while(leftstart<=leftend)
            {
                int mid=leftstart+(leftend-leftstart)/2;
                if(arr[mid]==-1) arr[mid]=mountainArr.get(mid);
                if(arr[mid]==target) return mid;
                else if(arr[mid]>target) leftend=mid-1;
                else leftstart=mid+1;
            }
        }
        if(target<=arr[rightstart] && target>=arr[rightend])
        {
            while(rightstart<=rightend)
            {
                int mid=rightstart+(rightend-rightstart)/2;
                if(arr[mid]==-1) arr[mid]=mountainArr.get(mid);
                if(arr[mid]==target) return mid;
                else if(arr[mid]>target) rightstart=mid+1;
                else rightend=mid-1;
            }
        }
        return -1;
    }
};