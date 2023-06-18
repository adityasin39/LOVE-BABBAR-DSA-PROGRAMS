class Solution {
public:
// one approach is to sort the array and then find the kth largest element.
// the second approach is to make a heap and then do heap sort.
// the third approach is to push all the elements in a priority queue which is by default a max heap and then pop k times to get the answer.
// The next approach is to make a min heap of first k elements and then for the remaining n-k elements check if the element is greater than the top of the min heap if it is then delete the top element and push this element into the min heap and it will rearrange itself and finally the top will have the kth largest element as the top of the min heap will have the smallest of the k elements of the min heap.
        // TC=O(nlogk) and SC=O(k)
        // priority_queue<int,vector<int>,greater<int>> pq;
        // for(int i=0;i<k;i++)
        // {
        //     pq.push(nums[i]);
        // }
        // for(int i=k;i<nums.size();i++)
        // {
        //     if(nums[i]>pq.top())
        //     {
        //         pq.pop();
        //         pq.push(nums[i]);
        //     }
        // }
        // return pq.top();
     //the next approach is the best approach and is based on the quicksort subroutine partition. Here we do the partition and get the pivotindex and then check if it is equal to the required index if it is then we have got our answer otherwise according to the index of pivot, we will know whther the kth largest element is to the left or right of pivot or just itself.This is known as quickselect algorithm.
     // TC=O(n) in best and average case and O(n^2) in worst case
     // used random pivot to improve the performance.
int partition(vector<int>& nums,int start, int end)
{
    int index=start+rand()%(end-start+1);
    swap(nums[start],nums[index]);
    int pivot=nums[start];
    int cnt=0;
    for(int i=start+1;i<=end;i++)
    {
        if(nums[i]<=pivot) cnt++;
    }
    int pivotIndex=start+cnt;
    swap(nums[start],nums[pivotIndex]);
    int i=start;
    int j=end;
    while(i<pivotIndex && j>pivotIndex)
    {
      while(i<pivotIndex && nums[i]<=nums[pivotIndex]) i++;
      while(j>pivotIndex && nums[j]>nums[pivotIndex]) j--;
      if(nums[i]>=nums[pivotIndex] && nums[j]<=nums[pivotIndex]) swap(nums[i++],nums[j--]);
    }
    return pivotIndex;
}
    int findKthLargest(vector<int>& nums, int k) {
        int start=0;
        int end=nums.size()-1;
        while(true)
       {
           int pivotIndex= partition(nums,start,end);
           if(pivotIndex==nums.size()-k) return nums[pivotIndex];
           if(pivotIndex>nums.size()-k)
           {
              end=pivotIndex-1;
           }
           else
           {
           start=pivotIndex+1;
           }
       }
    }
};