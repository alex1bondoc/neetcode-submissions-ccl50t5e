class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {};
        int cols[9] = {};
        int box[9] = {};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                int val =  board[i][j] - '1';
                if (rows[i] & 1 << val || cols[j] & 1 << val || box[(i / 3) * 3 + j/3] & 1 << val) return false;
                rows[i] |= 1 << val;
                cols[j] |= 1 << val;
                box[(i / 3) * 3 + j / 3] |= 1 << val;

            }
        }
        return true;
    }
};
