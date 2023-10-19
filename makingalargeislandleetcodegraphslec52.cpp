// we are using set to avoid the edge case when the same island is at the left as well as below then the same component parent gets added twice thus set is used.
class Solution {
public:
    class DisjointSet {
    private:
        

    public:
    vector<int> parent, rank, size;
        DisjointSet(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) { // will work for both 0 and 1 based indexing
                parent[i] = i;
                size[i] = 1;
                rank[i] = 0;
            }
        }

        int findUpar(int node) {
            if (parent[node] == node)
                return node;
            return parent[node] = findUpar(parent[node]); // path compression
        }

        void unionbyrank(int u, int v) {
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if (ulp_u == ulp_v)
                return;
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            } else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            } else {
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }

        void unionbysize(int u, int v) {
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if (ulp_u == ulp_v)
                return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else if (size[ulp_v] <= size[ulp_u]) {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); // Assuming all rows have the same number of columns
        DisjointSet ds(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int delrow[] = {-1, 0, 1, 0};
                    int delcol[] = {0, 1, 0, -1};
                    for (int k = 0; k < 4; k++) {
                        int nrow = i + delrow[k];
                        int ncol = j + delcol[k];
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                            int u = m * i + j;
                            int v = m * nrow + ncol;
                            if (ds.findUpar(u) != ds.findUpar(v)) {
                                ds.unionbysize(u, v);
                            }
                        }
                    }
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                unordered_set<int> st;
                if (grid[i][j] == 0) {
                    int delrow[] = {-1, 0, 1, 0};
                    int delcol[] = {0, 1, 0, -1};
                    for (int k = 0; k < 4; k++) {
                        int nrow = i + delrow[k];
                        int ncol = j + delcol[k];
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                            int u = n * nrow + ncol;
                            int ulp = ds.findUpar(u);
                            st.insert(ulp);
                        }
                    }
                }
                 int sum = 1;
                    for (auto it : st) {
                        sum += ds.size[it];
                    }
                    ans = max(ans, sum);
            }
        }
        if(ans==1)
        {
            for(int i=0;i<n*n;i++)
            {
                ans=max(ans,ds.size[i]);
            }
        }
        return ans;
    }
};
