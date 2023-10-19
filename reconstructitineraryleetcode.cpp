class Solution {
public:
    struct comp
    {
        bool operator()(vector<string> v1, vector<string> v2)
        {
            if(v1[0] != v2[0]) return v1[0] < v2[0];
            else return v1[1] < v2[1];
        }
    };

    bool dfs(string curr, unordered_map<string, vector<string>>& adj, vector<string>& res, int n)
    {
        if (res.size() == n + 1) return true;
        if (adj.find(curr) == adj.end()) return false;

        for (int i = 0; i < adj[curr].size(); i++)
        {
            string next = adj[curr][i];
            res.push_back(next);
            adj[curr].erase(adj[curr].begin() + i);
            if (dfs(next, adj, res, n)) return true;
            res.pop_back();
            adj[curr].insert(adj[curr].begin() + i, next);
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        sort(tickets.begin(), tickets.end(), comp());   
        unordered_map<string, vector<string>> adj;
        
        for (int i = 0; i < tickets.size(); i++)
        {
            string from = tickets[i][0];
            string to = tickets[i][1];
            adj[from].push_back(to);
        }

        vector<string> res;
        res.push_back("JFK");
        dfs("JFK", adj, res, n);
        return res;
    }
};
