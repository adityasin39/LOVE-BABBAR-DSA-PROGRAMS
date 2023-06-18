// always use quickselect algorithm for this question
    int partition(int nums[],int start, int end)
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
    int kthSmallest(int arr[], int l, int r, int k) {
         int start=0;
        int end=r;
        while(true)
       {
           int pivotIndex= partition(arr,start,end);
           if(pivotIndex==k-1) return arr[pivotIndex];
           if(pivotIndex>k-1)
           {
              end=pivotIndex-1;
           }
           else
           {
           start=pivotIndex+1;
           }
       }
        // priority_queue<int> pq;
        // for(int i=0;i<k;i++)
        // {
        //     pq.push(arr[i]);
        // }
        // for(int i=k;i<=r;i++)
        // {
        //     if(arr[i]<pq.top())
        //     {
        //         pq.pop();
        //         pq.push(arr[i]);
        //     }
        // }
        // return pq.top();
        // priority_queue<int,vector<int>,greater<int>> pq;
        // int ans=0;
        // for(int i=0;i<=r;i++)
        // {
        //     pq.push(arr[i]);
        // }
        // for(int i=0;i<k;i++)
        // {
        //     ans=pq.top();
        //     pq.pop();
        // }
        // return ans;
    }
};