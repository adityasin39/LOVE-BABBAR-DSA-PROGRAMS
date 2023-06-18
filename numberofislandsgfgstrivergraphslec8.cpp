   //Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
    // the above definition says that the island is surrounded by water which means that we have to take maximum number of 1s to make our island.
    // The note also states that we have to check in all the 8 directions for the neighbours.
    // islands are made from connected 1s and graphs are also made of connected nodes so we will do traversal.
    // We are traversing the whole matrix and whenever we get a 1 we increase the count as we have got an island and we call the bfs for that starting point.
    // The bfs then marks all the island cells as visited so that we dont count the same island once again as we further traverse the matrix.
    // TC=O(n*m + 8*n*m) because the two for loops will run for n*m and the bfs wont be called for each cell of the matrix so the bfs complexity will get added and not multiplied.
    // In the worst case the matrix can have 1s in all the cells so 8*n*m+n*m will be the TC
    // SC=O(n*m+n*m) one for queue and the other for visited matrix.
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int row, int col)
    {
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=1;
          int n=grid.size();
        int m=grid[0].size();
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int delrow[]={-1,-1,0,1,1,1,0,-1};
            int delcol[]={0,1,1,1,0,-1,-1,-1};
            for(int j=0;j<8;j++)
            {
                int nrow=r+delrow[j];
                int ncol=c+delcol[j];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !visited[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    cnt++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return cnt;
    }
};