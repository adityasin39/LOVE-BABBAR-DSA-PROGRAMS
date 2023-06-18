// to get distinct islands, we can store all the islands's shape in a set so that we get unique ones only.
// to get the shape of an island, we take the first starting node of the bfs as the baserow and base col and then we traverse the whole island in a particular pattern.
// Like in the below solution, the pattern followed is up,right,down,left.
// We traverse the whole island according to the pattern and subtract the coordinates from the base coordinates and we push them into the set so that when any other island which has the same shape, traverses in the same pattern and subtracting the node coordinates from the base coordinates then we will get the same configuration resulting in no addition into the set.
// if you still dont understand then refer to https://takeuforward.org/data-structure/number-of-distinct-islands/
// TC=O(n*m+n*m*log(n*m)),SC=O(n*m)
class Solution {
    private:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited, int row, int col,vector<pair<int,int>>& shape,int baserow, int basecol)
    {
        shape.push_back({row-baserow,col-basecol});
        visited[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]==1 && !visited[nrow][ncol])
            {
                dfs(grid,visited,nrow,ncol,shape,baserow,basecol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    vector<pair<int,int>> shape;
                    dfs(grid,visited,i,j,shape,i,j);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};