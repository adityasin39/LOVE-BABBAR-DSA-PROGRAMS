// TC=O(9^m where m is the no. of spaces to be filled)
class Solution {
public:
  bool isPossible(vector<vector<char>>& board, int row, int col, char ch)
  {
       for(int i=0;i<9;i++)
       {
           if(board[i][col]==ch) return false;
           if(board[row][i]==ch) return false;
           if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false; // this is pure observation 3* (row/3) will give you 0,1,2 as there are 3 subboxes row-wise and from this calculation we get the particular subbox and then i/3 is to have the differnt cells of that subbox. Same goes for col.
       }
       return true;
  }
  bool solve(vector<vector<char>>& board, int row)
  {
      for(int i=row;i<board.size();i++) // checking each cell of the matrix
      {
          for(int j=0;j<board[i].size();j++)
          {
              if(board[i][j]=='.')
              {
                  for(char ch='1';ch<='9';ch++) //checking all possibilities
                  {
                    if(isPossible(board,i,j,ch))
                    {
                        board[i][j]=ch;
                       if(solve(board,i)==true) // this will be true when all the gaps are filled and we dont encounter any conflict and thus we return true so that we dont go ahead in our search.
                       {
                             return true;
                       }
                       else board[i][j]='.'; //this means that it is not a possible solution so we backtrack
                    }
                  }
                  return false; // this is done when we have explored all numbers from 1 to 9 and none of them can be placed in the gap so it is not a possible solution.
              }
          }
      }
      return true; // this means that we have found our answer
  }
    void solveSudoku(vector<vector<char>>& board) {
        int row=0;
        solve(board,row);// row is passed so that we dont start from row 0 after each 
        // recursive call.
    }
};