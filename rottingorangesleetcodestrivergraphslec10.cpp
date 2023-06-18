//In this approach, we can see that the adjacent oranges get rotten so this indicates that we need to use bfs. We will use a visited matrix to keep track of the rotten oranges.
// Initially we will put all the rotten oranges in the queue and then we will check on all four sides if there is a fresh orange. If we get a fresh orange then we will push in the queue and mark it as rotten in the visited matrix.
//If you dont understand then refer this https://takeuforward.org/data-structure/rotten-oranges/
// TC=O(m*n) and SC=O(m*n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int time=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},time});
                    visited[i][j]=2;
                }
            }
        }
       int ans=time;
        while(!q.empty())
        {
          int size=q.size();
          for(int k=0;k<size;k++)
          {
              pair<pair<int,int>,int> temp=q.front();
              q.pop();
              int i=temp.first.first;
              int j=temp.first.second;
              ans=temp.second;

              if(i-1>=0 && grid[i-1][j]==1 && visited[i-1][j]!=2)
              {
                  q.push({{i-1,j},ans+1});
                  visited[i-1][j]=2;
              }
               if(i+1<m && grid[i+1][j]==1 && visited[i+1][j]!=2)
              {
                  q.push({{i+1,j},ans+1});
                  visited[i+1][j]=2;
              }
               if(j-1>=0 && grid[i][j-1]==1 && visited[i][j-1]!=2)
              {
                  q.push({{i,j-1},ans+1});
                  visited[i][j-1]=2;
              }
               if(j+1<n && grid[i][j+1]==1 && visited[i][j+1]!=2)
              {
                  q.push({{i,j+1},ans+1});
                  visited[i][j+1]=2;
              }

          }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0) return -1;
            }
        }
        return ans;
    }
};