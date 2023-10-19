// if you dont understand then refer to https://www.youtube.com/watch?v=6tLuiY59iYk
class Solution {
public:
    bool isAnswer(vector<vector<int>>& safeness, int mid, int n)
    {
        queue<pair<int,int>> q;
        if(safeness[0][0]<mid) return false;
        q.push({0,0});
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0]=1;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            if(row==n-1 && col==n-1) return true;
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !visited[nrow][ncol] && safeness[nrow][ncol]>=mid)
                {
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> safeness(n,vector<int>(n,1e9));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    safeness[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && safeness[row][col]+1<safeness[nrow][ncol])
                {
                    safeness[nrow][ncol]=safeness[row][col]+1;
                    q.push({nrow,ncol});
                }
            }
        }
        int start=0;
        int end = 0;
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        end = max(end, safeness[i][j]);
    }
}

        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isAnswer(safeness,mid,n))
            {
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
        
    }
};