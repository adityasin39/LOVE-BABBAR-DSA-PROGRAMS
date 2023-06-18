class Solution {
public:
    bool isPossible(vector<vector<char>>& board, int row, int col, char ch) {
        board[row][col]='.';
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch ) return false;  // Check row
            if (board[row][i] == ch ) return false;  // Check column
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) {
                return false;  // Check 3x3 box
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    char ch = board[i][j];
                    if (!isPossible(board, i, j, ch)) {
                        return false;
                    }
                    board[i][j]=ch;
                }
            }
        }
        return true;
    }
};
