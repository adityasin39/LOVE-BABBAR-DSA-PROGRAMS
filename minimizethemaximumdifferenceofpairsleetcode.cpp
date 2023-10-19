// This is how I made sense of the question:

// Sort the list.
// Guess the minimum maximum difference.
// Count how many pairs in nums have a difference equal to or less than this guess.
// If the count is too high (more than or equal to p) then guess a lower value.
// Otherwise, guess a higher value.
// The smallest guess will be 0 and the highest guess will be nums[numsSize-1] - nums[0] (assuming nums is sorted).
// The answer will be the smallest guess that gives a pair count equal to p
class Solution {
public:
    bool isPossible(vector<int>& nums, int p, int mid, int n)
    {
        int cnt=0;
        int i=0;
        while(i<n-1)
        {
            if(nums[i+1]-nums[i]<=mid)
            {
                cnt++;
                i+=2;
            }
            else i++;
            if(cnt>=p) return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums[n-1]-nums[0];
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(nums,p,mid,n))
            {
              end=mid-1;
              ans=mid;
            }
            else start=mid+1;
        }
        return ans;
    }
};