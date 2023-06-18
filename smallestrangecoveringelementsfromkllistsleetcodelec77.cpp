//In this approach,we push the first element of all the lists in the minheap and then find out the min and max values thus this range will cover one element from all the lists and to minimize the range we will have to increase min so we update the min value by taking the next element of the same array.
// if you dont understand then refer to love babar original video.
// TC=O(k+nlogk)
class Solution {
public:
  class Info
  { 
      public:
      int val;
      int i;
      int j;
      Info(int val, int row, int col)
      {
          this->val=val;
          i=row;
          j=col;
      }
  };
  struct comp
  {
      bool operator()(Info a, Info b)
      {
          return a.val>b.val;
      }
  };
    vector<int> smallestRange(vector<vector<int>>& nums) {
       priority_queue<Info, vector<Info>, comp> minHeap; //we take minheap because we want to get min element in O(1) time as we have to increase min
       int k=nums.size();
       int maxi=INT_MIN;
       int mini=INT_MAX;
       for(int i=0;i<k;i++)
       {
           maxi=max(maxi,nums[i][0]);
           Info temp(nums[i][0],i,0);
           minHeap.push(temp);
       }
       mini=minHeap.top().val;
        int range_start=mini;
       int range_end=maxi;

       while(minHeap.size()==k)
       {
           Info temp=minHeap.top();
           minHeap.pop();
            mini=temp.val;
           if(maxi-mini<range_end-range_start)
           {
               range_start=mini;
               range_end=maxi;
           }
           int col=temp.j;
           int row=temp.i;
           if(col+1<nums[row].size())
           {
               Info next_temp(nums[row][col+1],row,col+1);
               minHeap.push(next_temp);
               maxi=max(maxi,next_temp.val);
           }
       }
       vector<int> ans={range_start,range_end};
       return ans;
    }
};