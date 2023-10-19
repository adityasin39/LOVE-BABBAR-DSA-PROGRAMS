class Solution {
public:
      void dfs(int row, int col, vector<vector<int>>& board, int m, int n)
    {
        board[row][col]=2;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]==0) dfs(nrow,ncol,board,m,n);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==0) dfs(0,i,grid,m,n);
            if(grid[m-1][i]==0) dfs(m-1,i,grid,m,n);
        }
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0) dfs(i,0,grid,m,n);
            if(grid[i][n-1]==0) dfs(i,n-1,grid,m,n);
        }  
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    cnt++;
                    dfs(i,j,grid,m,n);
                }
            }
        }
        return cnt;
    }
};