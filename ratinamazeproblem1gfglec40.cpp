// if you dont understand then refer to https://www.youtube.com/watch?v=bLGZhJlt4y0
// TC is O(3*n^2) as after one move three moves are left for both the approaches
// SC is O(n^2) as in the worst case we would move to all blocks and then reach the destination for both the approaches
// both approach 1 and 2 are same but in the 2nd approach, instead of writing if 4 times we have used a loop
// Approach 1
class Solution{
    private:
    bool isPossible(vector<vector<int>> m,int x, int y,vector<vector<int>> visited,int n)
    {
//here we check if it is possible to take the next move. The conditions for the next move are 1. the rat should be in the boundary 2. the block should be 1 and 3. it should not have been visited before
        if(x>=0 && x<=n-1 && y>=0 && y<=n-1 && m[x][y]==1 && visited[x][y]==0) return true;
        return false;
    }
    void solve(vector<vector<int>> m, vector<string>& ans, string path, int x, int y,vector<vector<int>>& visited,int n  )
    {
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return;
        }
//we wanted the answer in lexo order which is D,L,R,U so we wrote the if statement in that order so in short no need to sort the answer
        // down
        if(isPossible(m,x+1,y,visited,n))
        {
            visited[x][y]=1; 
            solve(m,ans,path+'D',x+1,y,visited,n);
            visited[x][y]=0; // backtracking for future answers
        }
        // left
         if(isPossible(m,x,y-1,visited,n))
        {
            visited[x][y]=1;
            solve(m,ans,path+'L',x,y-1,visited,n);
            visited[x][y]=0;
        }
        //right
         if(isPossible(m,x,y+1,visited,n))
        {
            visited[x][y]=1;
            solve(m,ans,path+'R',x,y+1,visited,n);
            visited[x][y]=0;
        }
        //up
         if(isPossible(m,x-1,y,visited,n))
        {
            visited[x][y]=1;
            solve(m,ans,path+'U',x-1,y,visited,n);
            visited[x][y]=0;
        }
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0)
        {
            return ans;
        }
        string path="";
//we need visited because otherwise we would go through the same path again and again
        vector<vector<int>> visited(n,vector<int>(n,0)); // all initialized to 0 , n ke andar n 2-d array kind of thing
        int x=0;
        int y=0;
        solve(m,ans,path,x,y,visited,n);
        return ans;
    }
};
// Approach 2
// #include <bits/stdc++.h> 
// using namespace std;
//   bool isPossible(vector<vector<int>> &arr,int x, int y,vector<vector<int>>& visited,int n)
//     {
//         if(x>=0 && x<=n-1 && y>=0 && y<=n-1 && arr[x][y]==1 && visited[x][y]==0) return true;
//         return false;
//     }
// void solve(vector<vector<int>> &arr, int n, string path, vector<string> &ans,
//           vector<vector<int>> &visited, int x, int y, int dx[], int dy[])

// {
//     if(x==n-1 && y==n-1)
//     {
//         ans.push_back(path);
//         return;
//     }
//     string res="DLRU";
//     for (int i = 0; i < 4; i++) {

//       if (isPossible(arr, x + dx[i],y+dy[i],visited,n))
//       {
//           visited[x][y]=1;
//           solve(arr,n,path+res[i],ans,visited,x+dx[i],y+dy[i],dx,dy);
//           visited[x][y]=0;
//       }
//     }
// }
// vector<string> searchMaze(vector<vector<int>> &arr, int n) {
//   vector<string> ans;
//   if (arr[0][0] == 0)
//     return ans;
//   string path = "";
//   int x = 0;
//   int y = 0;
//   vector<vector<int>> visited(n, vector<int>(n, 0));
//   int dx[] = {1, 0, 0, -1}; // this shows the deviation for D,L,R,U
//   int dy[] = {0, -1, 1, 0};
//   solve(arr, n, path, ans, visited, x, y, dx, dy);
//   return ans;
// }