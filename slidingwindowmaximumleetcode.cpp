// if you dont understand then refer to page 81 of https://cses.fi/book/book.pdf
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        int left = 0;
        int right = k - 1;
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (q.empty()) q.push_back(nums[i]);
            else {
                while (!q.empty() && q.back() < nums[i]) {
                    q.pop_back();
                }
                q.push_back(nums[i]);
            }
        }
        ans.push_back(q.front());
        if (!q.empty() && nums[left] == q.front()) q.pop_front();
        left++;
        right++;
        while (right < n) {
            while (!q.empty() && q.back() < nums[right]) {
                q.pop_back();
            }
            q.push_back(nums[right]);
            ans.push_back(q.front());
            
            if (!q.empty() && nums[left] == q.front()) q.pop_front();
            left++;
            right++;
        }
        return ans;
    }
};