// Kadane's algorithm:
// in this algorithm, we iterate over the array one by one and we have two variables sum=0 and maxi=INT_MIN
// first we add the array element to the sum and then compare the sum with the maxi variable, if the sum is greater then that means we have fount out a subarray with a greater sum so we update it but if the sum is negative then carrying it forward will be a loss so we set sum=0 whenever the sum becomes negative and do the same thing forward. TC=O(n) and SC=O(1) 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0) sum=0;
        }
        return maxi;
    }
};
// to print the maximum subarray
// ansstart to ansend will have the maximum subarray
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum=0;
//         int maxi=INT_MIN;
//         int start=-1;
//         int ansstart=-1;
//         int ansend=-1;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(sum==0) start=i;
//             sum+=nums[i];
//             if(sum>maxi)
//             {
//                 maxi=sum;
//                 ansstart=start;
//                 ansend=i;
//             }
//             if(sum<0) sum=0;
//         }
//         return maxi;
//     }
// };