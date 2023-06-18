class Solution {
public:
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
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int j=0;j<4;j++)
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