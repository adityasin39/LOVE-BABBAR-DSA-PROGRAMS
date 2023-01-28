// Approach 1 which is not in place. TC is O(n) and memory is O(n).
// n sized array has 0 to n-1 index and similarly on doing %n the result range will be 0 to n-1 so to rotate the array we have used this trick.
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
//         vector<int> temp(n,0);
//         for(int i=0;i<n;i++)
//         {
//           temp[(i+k)%n]=nums[i];
//         }
//         nums=temp;
//     }
// };
// Approach 2 which is an in place method with TC -O(n) and memory O(1)
//always use this method.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        if(k==0) return;
       reverse(nums.begin(),nums.end());
       reverse(nums.begin(),nums.begin()+k);
       reverse(nums.begin()+k,nums.end());
    }
};