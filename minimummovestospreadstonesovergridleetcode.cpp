// cant be solved by bfs
// Approach : A cell should only donate if it has >1 stone, and another cell should accept if it has 0 stones, right.

// Breadth First Search : Now if you are thinking of bfs, let me tell you the issue, Suppose there is 2 stones at (0,0) and 2 stones at (2,1) and you wanted to move them to (2,0) and (2,2) . Ideally (0,0) -> (2,0) and (2,1) -> (2,2) but bcz of bfs, it will try to find out the stone at nearest position and (2,0) will go for (2,1) resulting in longer number of moves.

// Backtracking : Think of solving this in backtracking manner. For every child try to get stone from every parent and then return the path with minimum moves.
// if you dont understand then refer to prakhar agarwal video
class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<pair<int,int>>& zeroes, vector<pair<int,int>>& extras, int curZeroIdx)
    {
        if(curZeroIdx==zeroes.size()) return 0;
        int zeroX=zeroes[curZeroIdx].first;
        int zeroY=zeroes[curZeroIdx].second;
        int ans=1e6;
        for(int i=0;i<extras.size();i++)
        {
            int extrasX=extras[i].first;
            int extrasY=extras[i].second;
            if(grid[extrasX][extrasY]>1)
            {
                grid[extrasX][extrasY]--;
                grid[zeroX][zeroY]=1;
                ans=min(ans,(abs(extrasX-zeroX)+abs(extrasY-zeroY))+solve(grid,zeroes,extras,curZeroIdx+1));
                grid[extrasX][extrasY]++;
                grid[zeroX][zeroY]=0;
            }
        }
        return ans;
    }

    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>> zeroes;
        vector<pair<int,int>> extras;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i][j]==0) zeroes.push_back({i,j});
                if(grid[i][j]>1) extras.push_back({i,j});
            }
        }
        return solve(grid,zeroes,extras,0);
    }
};