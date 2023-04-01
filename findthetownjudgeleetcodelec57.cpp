// The function works by first creating a vector balance of size N+1. This vector is used to keep track of the number of people each person trusts minus the number of people who trust that person. In other words, for each i in trust, we decrement balance[t[0]] (since t[0] trusts someone) and increment balance[t[1]] (since t[1] is trusted by someone).
// TC=O(n) and SC=O(n)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<int> balance(n+1,0);
        for(auto t: trust)
        {
            balance[t[0]]--;
            balance[t[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(balance[i]==n-1) return i;
        }
        return -1;

    }
};
// brute force TC=O(n*n) and SC=O(1) got accepted
//   for(int i=1;i<=n;i++)
//       {
//         int cnt=0;
//           for(int j=0;j<trust.size();j++)
//           {
//               if(trust[j][1]==i) cnt++;
//           }
//           if(cnt!=n-1) continue;
//           int j;
//           for( j=0;j<trust.size();j++)
//           {
//               if(trust[j][0]==i) break;
//           }
//           if(j!=trust.size()) continue;
//           return i;
//       }
//       return -1