// Optimized approach.
// here we are doing the work of isSafe funtion in O(1) by some hashing and observation.
class Solution {
public:
     void solve(int row, int col,vector<vector<string>>& ans,vector<string> board,int n,vector<int> leftrow, vector<int> upperdiagonal, vector<int> lowerdiagonal)
    {
        if(col>n-1)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            row=i;
            if(leftrow[row]==0 && upperdiagonal[row+col]==0 && lowerdiagonal[n-1+col-row]==0)
            {
               board[row][col]='Q';
               leftrow[row]=1;
               upperdiagonal[row+col]=1;
               lowerdiagonal[n-1+col-row]=1;
               solve(row,col+1,ans,board,n,leftrow,upperdiagonal,lowerdiagonal);
               //backtracking
               board[row][col]='.';
                leftrow[row]=0;
               upperdiagonal[row+col]=0;
               lowerdiagonal[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board;
       for(int i=0;i<n;i++)
       {
           string row(n,'.');
           board.push_back(row);
       }
       int row=0;
       int col=0;
       vector<int> leftrow(n,0); // we put 1 if there is a single queen in that particular row and then in O(1) we check if it is safe to put another queen.
       vector<int> upperdiagonal(2*n-1,0); // these two lines are an observation which is obtained if you add row and col of each chess cell and then observe.
       vector<int> lowerdiagonal(2*n-1,0);// add n-1+col-row for each cell and then observe.
       //memorize these basically.
       solve(row,col,ans,board,n,leftrow,upperdiagonal,lowerdiagonal);
       return ans;
    }
};
// class Solution {
// public:
//  bool isSafe(int row, int col,vector<string> board, int n)
//  {
//      for(int i=0;i<col;i++)
//      {
//          if(board[row][i]=='Q') return false;
//      }
//      int i=row-1;
//      int j=col-1;
//      while(i>=0 && j>=0)
//      {
//          if(board[i][j]=='Q') return false;
//          i--;
//          j--;
//      }
//      i=row+1;
//      j=col-1;
//      while(i<n && j>=0)
//      {
//          if(board[i][j]=='Q')  return false;
//          i++;
//          j--;
//      }
//      return true;
//  }
//     void solve(int row, int col,vector<vector<string>>& ans,vector<string> board,int n)
//     {
//         if(col>n-1)
//         {
//             ans.push_back(board);
//             return;
//         }
//         for(int i=0;i<n;i++)
//         {
//             row=i;
//             if(isSafe(row,col,board,n))
//             {
//                board[row][col]='Q';
//                solve(row,col+1,ans,board,n);
//                board[row][col]='.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//        vector<vector<string>> ans;
//        vector<string> board;
//        for(int i=0;i<n;i++)
//        {
//            string row(n,'.');
//            board.push_back(row);
//        }
//        int row=0;
//        int col=0;
//        solve(row,col,ans,board,n);
//        return ans;
//     }
// };