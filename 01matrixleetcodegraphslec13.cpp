// if you do dfs for each cell then you will get get stack overflow error even though you do memoization.
// the same thing goes for bfs ie. if you do bfs for each cell then you will get tle.
// the only solution is to do multi source bfs as done below.
// if you dont understand then refer to striver notes of this lec
// TC=O(m*n)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
       vector<vector<int>> dist(m,vector<int>(n,0));
       vector<vector<int>> visited(m,vector<int>(n,0));
       queue<pair<pair<int,int>,int>> q;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(mat[i][j]==0) {
                   q.push({{i,j},0});
                   visited[i][j]=1;
               }
           }
       }
    while(!q.empty())
    {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int distance=q.front().second;
        q.pop();
        dist[row][col]=distance;
        int delrow[]={-1,0,1,0};
              int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if((nrow>=0 && nrow<m && ncol>=0 && ncol<n) && !visited[nrow][ncol] && mat[nrow][ncol]!=0)
            {
                q.push({{nrow,ncol},distance+1});
                visited[nrow][ncol]=1;
            } 
        }
    }
    return dist;
    }
};