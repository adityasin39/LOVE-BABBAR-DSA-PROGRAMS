class Solution {
public:
    int minSizeSubarray(vector<int>& nums, long long target) {
        long long n = nums.size();
        long long tot = accumulate(nums.begin(), nums.end(), 0LL); // Use 0LL for explicit long long, this is important otherwise you will get overflow
        long long cnt = target / tot;
        long long rem = target % tot;
        if (rem == 0) return cnt * n;
        target = rem;
        for (int i = 0; i < n; i++) nums.push_back(nums[i]);
        int left = 0;
        int right = 0;
        long long ans = INT_MAX; // Change ans to long long
        long long sum = 0;
        sum += (long long)nums[right];
        while (right < nums.size()) {
            while (sum > target) {
                sum -= nums[left];
                left++;
            }
            if (sum == target) ans = min(ans, (long long)(right - left + 1)); // Calculate ans separately
            right++;
            if (right < nums.size()) sum += (long long)nums[right];
        }
        if (ans == INT_MAX) return -1;
        return (int)(ans + cnt * n); // Cast ans back to int for the final result
    }
};
