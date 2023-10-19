// if you dont understand then refer to techtalk video
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> left_sum(n, 0);
        vector<long long> right_sum(n, 0);
        stack<int> st;
        long long total = 0;
        for (int i = 0; i < maxHeights.size(); i++) {
            while (!st.empty() && maxHeights[i] < maxHeights[st.top()]) {
                int idx = st.top();
                st.pop();
                long long multiplier = 0;
                if (st.empty()) multiplier = idx + 1;
                else multiplier = idx - st.top();
                total -= (long long)maxHeights[idx] * multiplier;
            }
            long long multiplier = 0;
            if (st.empty()) multiplier = i + 1;
            else multiplier = i - st.top();
            total += (long long)maxHeights[i] * multiplier;

            st.push(i);
            left_sum[i] = total;
        }
        while (!st.empty()) st.pop();
        total = 0;
        for (int i = maxHeights.size() - 1; i >= 0; i--) {
            while (!st.empty() && maxHeights[i] < maxHeights[st.top()]) {
                int idx = st.top();
                st.pop();
                long long multiplier = 0;
                if (st.empty()) multiplier = maxHeights.size() - idx;
                else multiplier = st.top() - idx;
                total -= (long long)maxHeights[idx] * multiplier;
            }
            long long multiplier = 0;
            if (st.empty()) multiplier = maxHeights.size() - i;
            else multiplier = st.top() - i;
            total += (long long)maxHeights[i] * multiplier;
            st.push(i);
            right_sum[i] = total;
        }
        long long ans = 0;
        for (int i = 0; i < left_sum.size(); i++) {
            ans = max(ans, left_sum[i] + right_sum[i] - maxHeights[i]);
        }
        return ans;
    }
};
