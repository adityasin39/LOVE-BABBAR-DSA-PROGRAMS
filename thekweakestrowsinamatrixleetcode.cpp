// in the case of vector as well as max heap, tie is broken by comparing the second element. so  {5,3} is greater than {5,2}
//Approach 1
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       int n=mat[0].size();
       for(int i=0;i<mat.size();i++) mat[i].push_back(i);
       sort(mat.begin(),mat.end());
       vector<int> ans;
       for(int i=0;i<k;i++) ans.push_back(mat[i][n]);
       return ans;
    }
};
// Approach 2
// class Solution {
// public:
//     int binarysearch(vector<int>& mat)
//     {
//        int start=0;
//        int end=mat.size()-1;
//        while(start<=end)
//        {
//            int mid=start+(end-start)/2;
//            if(mat[mid]==1) start=mid+1;
//            else end=mid-1;
//        }
//        return start;
//     }
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//       priority_queue<pair<int,int>> pq;
//       for(int i=0;i<mat.size();i++)
//       {
//           int cnt=binarysearch(mat[i]);
//           pq.push({cnt,i});
//           if(pq.size()>k) pq.pop();
//       }
//       vector<int> ans;
//       while(!pq.empty())
//       {
//           int idx=pq.top().second;
//           ans.push_back(idx);
//           pq.pop();
//       }
//       reverse(ans.begin(),ans.end());
//       return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         int idx=0;
//         for(int i=0;i<k;i++)
//         {
//             int cnt=0;
//             for(int j=0;j<mat[0].size();j++){
//                 if(mat[i][j]==1) cnt++;
//             }
//             pq.push({cnt,i});
//             idx++;
//         }
//         vector<pair<int,int>> res;
//         while(idx<mat.size()){
//         int cnt=0;
//         res.push_back({pq.top().first,pq.top().second});
//         pq.pop();
//         for(int j=0;j<mat[0].size();j++) if(mat[idx][j]==1) cnt++;
//         pq.push({cnt,idx});
//         idx++;
//         }
//         while(!pq.empty()) 
//         {
//             res.push_back({pq.top().first,pq.top().second});
//             pq.pop();
//         }
//         sort(res.begin(),res.end());
//         vector<int> ans(k);
//         for(int i=0;i<k;i++) ans[i]=res[i].second;
//         return ans;
//     }
// };