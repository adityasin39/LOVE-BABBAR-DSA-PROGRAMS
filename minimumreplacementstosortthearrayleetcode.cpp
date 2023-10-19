// Apparently this was a Google interview question, that's why it is purely mathematical I guess.

// We need to make the array non decreasing by splitting the numbers.

// If we split a number, it will get even smaller.

// We want to make subsequent numbers either equal or in increasing order.

// So, this implies that we don't need to do anything with the last element, if we split it, it'll further decrease the last element, which is supposed to be the greatest after the sorting is done, so we leave that element as it is.

// We iterate backwards from the second last element.

// If we get two number in order like this 13 7.

// The optimal way to split 13 here will be to take as minimum steps and split it such that it's parts are <= 7.

// Split it 6 , 7.

// How to get this?

// Use this formula

// Steps to split = (nums[i] - 1)/last

// New smallest element formed (last) = nums[i]/(steps+1).

// ans += steps.
// imagine we had next sequence: 19 6.
// In how many parts we should split 19? ceil (19 / 6) = 4.
// How many steps we need to perform this? 3 (i.e. steps = parts - 1):
// 14 5 6
// 9 5 5 6
// 4 5 5 5 6

// How we know what will be the new last number after the split?
// We know that we should split number to most equal parts, so simply divide floor(19 / parts) = floor(19/4) = 4;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int last=nums[nums.size()-1];
        long long ans=0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(last<nums[i])
            {
               int steps=ceil(nums[i]/(double)last)-1;
               last=nums[i]/(steps+1);
               ans+=steps;
            }
            else last=nums[i];
        }
        return ans;
    }
};