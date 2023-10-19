// iterative better approach
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
       int i=0;
       vector<vector<int>> ans;
       vector<int> subans(k,0);
       while(i>=0)
       {
           subans[i]++;
           if(subans[i]>n) i--;
           else if(i==k-1) ans.push_back(subans);
           else
           {
               i++;
               subans[i]=subans[i-1];
           }
       }   
       return ans;
    }
};
// backtracking
// class Solution {
// public:
//     void solve(int num, int cnt, int k, vector<vector<int>>& ans, int n, vector<int>& subans)
//     {
//       if(cnt==k)
//       {
//           ans.push_back(subans);
//           return;
//       }
//       for(int j=num+1;j<=n;j++)
//       {
//           subans.push_back(j);
//           solve(j,cnt+1,k,ans,n,subans);
//           subans.pop_back();
//       }
//     }
//     vector<vector<int>> combine(int n, int k) {
//         vector<vector<int>> ans;
//         vector<int> subans;
//         for(int i=1;i<=n;i++)
//         {
//            subans.push_back(i);
//            solve(i,1,k,ans,n,subans);
//            subans.pop_back();
//         }
//         return ans;
//     }
// };