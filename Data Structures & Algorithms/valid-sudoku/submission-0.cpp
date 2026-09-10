class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') continue;

                pair<int, int> square_key = {row / 3, col / 3};

                if (rows[row].count(board[row][col]) || cols[col].count(board[row][col]) || squares[square_key].count(board[row][col])) return false;
                
                rows[row].insert(board[row][col]);
                cols[col].insert(board[row][col]);
                squares[square_key].insert(board[row][col]);
            }
        }
        return true;
    }
};
