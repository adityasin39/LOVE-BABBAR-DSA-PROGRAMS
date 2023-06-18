#include <bits/stdc++.h>

using namespace std;
//Sort both arrays in non-decreasing order.
// Initialize a max heap (priority queue) to store combinations.
// Push the combination of the last element from both arrays into the max heap along with their sum and indices (n-1, m-1), where n and m are the sizes of the arrays.
// While the max heap is not empty and you still need to find k combinations:
// Pop the maximum sum combination from the max heap.
// Store the combination in your result.
// If the index of the element from the first array is greater than 0, push the combination of the previous element from the first array and the current element from the second array along with their sum and indices.
// If the index of the element from the second array is greater than 0, push the combination of the current element from the first array and the previous element from the second array along with their sum and indices.
// we have used a set so that we dont get the same sum combination.
// TC=O(nlogn) SC=O(n)
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> ans;
	set<pair<int,int>> st;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
    st.insert({n - 1, n - 1});
    while (k > 0) {
        pair<int, pair<int, int>> top = pq.top();
        int sum = top.first;
        int idx1 = top.second.first;
        int idx2 = top.second.second;
        ans.push_back(sum);
        pq.pop();
        
        if (idx1 - 1 >= 0 && st.find({idx1-1,idx2})==st.end()) {
            pq.push({a[idx1 - 1] + b[idx2], {idx1 - 1, idx2}});
			st.insert({idx1-1,idx2});
        }
        if (idx2 - 1 >= 0 && st.find({idx1,idx2-1})==st.end()) {
            pq.push({a[idx1] + b[idx2 - 1], {idx1, idx2 - 1}});
			st.insert({idx1,idx2-1});
        }
        
        k--;
    }
    
    return ans;
}
