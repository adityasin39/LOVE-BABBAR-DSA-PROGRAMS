// here i have listed down two approaches.
// Approach 1 which is a lazy approach.
//in this approach, we have first found out the minimum element(pivot) in the rotated sorted array and then we check if the target is in between the pivot and the last element, if this is true then it means that the target is on the second line , so apply binary search on the second line only and if the target is on the first line, apply binary search on the first line only.
// class Solution {
// public:

//     int search(vector<int>& nums, int target) {
//         int n=nums.size();
//         int pivot;
//         int start=0;
//         int end=n-1;
//         while(start<=end)
//         {
//             int mid=start+(end-start)/2;
//             if(nums[mid]>=nums[0]) start=mid+1;
//             else end=mid-1;
//         }
//              if(start==n) pivot=0;
//              else pivot=start;
             
        // if target is on the second line
//         if(target<=nums[n-1] && target>=nums[pivot])
//         {
//             start=pivot;
//             end=n-1;
//               while( start<=end)
//     {
//         int m= start+(end- start)/2;
//         if(nums[m]==target) return m;
//         else if(nums[m]>target) end=m-1;
//         else start=m+1;
//     }
//         }
         //if target is on the first line.
//     else
//     {
//                   start=0;
//             end=pivot-1;
//               while( start<=end)
//     {
//         int m= start+(end- start)/2;
//         if(nums[m]==target) return m;
//         else if(nums[m]>target) end=m-1;
//         else start=m+1;
//     }
//     }
//     if(start>end) return -1;

    
// return 0;
//     }
// };
// Approach 2
// in this approach, first we find out mid and then check if the mid lies in the left sorted part if this is true then we check if the target also lies in the left sorted part if this is true then we do end=mid-1 otherwise that means that the target lies in the right sorted part so we do start=mid+1. If mid lies on the right sorted part then do the similar thing. 
// if you dont understand the solution here then go to strivers solution on youtube.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return mid;
            //for left sorted part
           if(nums[mid]>=nums[start])
            {
                if(target<=nums[mid] && target>=nums[start]) end=mid-1;
                else start=mid+1;
            }
            // for right sorted part
            else
            {
                if(target>=nums[mid] && target<=nums[end]) start=mid+1;
                else end=mid-1;
            }
        }
        return -1;
    }
};