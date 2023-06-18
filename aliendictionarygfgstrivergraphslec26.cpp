// Follow up: When is the dict wrong?
// Ans: 1. if there are two strings like abcd and abc and abcd is appearing before abc.
// 2. if there is a cyclic dependency like abc,bat,ade as this indicates a<b and b<a which is wierd.
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        vector<int> indegree(K,0);
        int i=0;
        int j=1;
        while(j<N)
        {
            int k=0;
            int l=0;
            while(k<dict[i].size() && l<dict[j].size())
            {
                if(dict[i][k]!=dict[j][l])
                {
                    int u=dict[i][k]-'a';
                    int v=dict[j][l]-'a';
                    adj[u].push_back(v);
                    indegree[v]++;
                    break;
                }
                k++;
                l++;
            }
            i++;
            j++;
        }
        queue<int> q;
        for(int i=0;i<K;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        string ans="";
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            ans+=temp+'a';
            for(auto it: adj[temp])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans;
    }
};