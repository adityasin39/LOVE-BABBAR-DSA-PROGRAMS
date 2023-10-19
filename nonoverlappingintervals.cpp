// Approach 1 best approach
//  e.g. [ [1,4], [2,3], [3,4] ], the interval with early start might be very long and incompatible with many intervals. But if we choose the interval that ends early, we'll have more space left to accommodate more intervals. Hope it helps.
class Solution {
public:
    struct comp
    {
       bool operator()(vector<int> itv1, vector<int> itv2)
       {
           return itv1[1]<itv2[1];
       }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp());
        int end=intervals[0][1];
        int cnt=1;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=end)
            {
               cnt++;
               end=intervals[i][1];
            }
        }
        return intervals.size()-cnt;
    }
};
// Approach 2
// class Solution {
// public:
//     int lowerbound(vector<vector<int>>& intervals, int idx, int n)
//     {
//         int start=idx+1;
//         int end=n-1;
//         int ans=-1;
//         while(start<=end)
//         {
//             int mid=start+(end-start)/2;
//             if(intervals[mid][0]>=intervals[idx][1])
//             {
//               ans=mid;
//               end=mid-1;
//             }
//             else start=mid+1;
//         }
//         return ans;
//     }
//     int solve(vector<vector<int>>& intervals, int idx, int n, vector<int>& dp)
//     {
//         if(idx>n-1) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         int nextIdx=lowerbound(intervals,idx,n);
//         int pick=1+(nextIdx==-1?0:solve(intervals,nextIdx,n,dp));
//         int notpick=solve(intervals,idx+1,n,dp);
//         return dp[idx]=max(pick,notpick);
//     }
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end());
//         int n=intervals.size();
//         vector<int> dp(n+1,-1);
//         return n-solve(intervals,0,n,dp);
//     }
// };