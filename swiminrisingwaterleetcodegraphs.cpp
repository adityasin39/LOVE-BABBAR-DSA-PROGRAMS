// the question is very difficult to understand
// refer the below explanation of the question
//Bad problem wording. Based on comments in the editorial, it seems like:
// What they really mean is that the surface is flat (elevation 0, "sea level", whatever)
// But it has holes. position i,j has a hole which is grid[i][j] deep.
// The holes slowly fill up 1 unit of height for each unit of time.
// When the hole is full (water level at elevation 0) further water pouring into that cell miraculously disappears.
// (Not like other problems where you have to track spillover into neighboring cells)
// To get "out of" and "into"" that hole at time t you need grid[i][j] <= t
// if you carefully observe, this problem is similar to path with minimum effort problem
// so, as you go through a path, the time that is maximum in that path will be required to cover that path because if the time has not reached the value to fill the largest hole, then how will you cover the path.
// so you have to check all the paths and then return the minimum time of them.
// ie. minimum of maximum time of all the paths so it is similar to path with minimum effort.
// if you still dont understand then refer to neetcode
// we need visited array as we know that dijkstra is greedy so it will always take a path with minimum time first at each decision moment hence no need to consider other paths hence we mark the cells as visited as soon as we push them.
//Since we are being greedy, every time we add a cell to Visit, we are guaranteeing that the path we took to get to this cell, has minimized the heights. In other words, if we visit Cell X and add it to the MinHeap and Visit Set, we are doing so because we know that there doesnt exist ANY other path in the entire grid, where the max height we had to take along the path, is any smaller.
//So we dont need to check every single path leading to Cell X, we only need to check the path where the Max Height is minimized.
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        visited[0][0]=1;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int cost=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==n-1) return cost;
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !visited[nrow][ncol])
                {
                    int newcost=max(cost,grid[nrow][ncol]);
                    pq.push({newcost,{nrow,ncol}});
                    visited[nrow][ncol]=1;
                }
            } 
        }
        return -1;
    }
};