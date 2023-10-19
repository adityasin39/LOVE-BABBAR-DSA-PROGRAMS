// TC=O(m*n*4) because in the worst case each cell will be colored so n*m and then for each cell 4 times the loop will run
// you dont need visited array because as soon as the color is changed then that color change will act as visited
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image; // this is important to understand
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> q;
        int initialColor=image[sr][sc]; // this is important to understand
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int drow=row+delrow[i];
                int dcol=col+delcol[i];
                if(drow>=0 && drow<m && dcol>=0 && dcol<n && image[drow][dcol]==initialColor) {
                    q.push({drow,dcol});
                    image[drow][dcol]=color;
                }
            }
        }
        return image;
    }
};