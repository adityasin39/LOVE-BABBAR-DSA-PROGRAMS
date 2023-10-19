// All the "O" that are not directly/indirectly connected to the "O" on the boundary line, will be captured and converted into "X"
// Just traverse the matrix once, and as soon as your enounter a boundary line that has a "O" in it, run DFS on this "O" and "Save" all the nehgbours of this "O" from being captured by calling them "S"
// Now traverse the matrix again and capture all the "O" that you can inside the matrix except the boundary line
// Rename the "Save" O back to "O"
// Done!
// TC=O(m*n*4 + m + m*n*4 + n + m*n)
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, int m, int n)
    {
        board[row][col]='S';
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]=='O') dfs(nrow,ncol,board,m,n);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O') dfs(0,i,board,m,n);
            if(board[m-1][i]=='O') dfs(m-1,i,board,m,n);
        }
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O') dfs(i,0,board,m,n);
            if(board[i][n-1]=='O') dfs(i,n-1,board,m,n);
        }  
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='S') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};