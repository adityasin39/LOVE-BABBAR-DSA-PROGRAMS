//2,3,6,5,4,1
// Solution:
// Step1, from right to left, find the first number which not increase in a ascending order. In this case which is 3.
// Step2, here we can have two situations:

// We cannot find the number, all the numbers increasing in a ascending order. This means this permutation is the last permutation, we need to rotate back to the first permutation. So we reverse the whole array, for example, 6,5,4,3,2,1 we turn it to 1,2,3,4,5,6.

// We can find the number, then the next step, we will start from right most to leftward, try to find the first number which is larger than 3, in this case it is 4.
// Then we swap 3 and 4, the list turn to 2,4,6,5,3,1.
// Last, we reverse numbers on the right of 4, we finally get 2,4,1,3,5,6.
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=n-1;
        while(j>i && nums[j]<=nums[i]) j--;
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
    }
};