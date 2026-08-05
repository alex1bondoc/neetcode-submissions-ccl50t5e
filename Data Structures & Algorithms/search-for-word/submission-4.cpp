class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i{}; i < board.size(); ++i) {
            for (int j{}; j < board[0].size(); ++j) {
                if (backtrack(i, j, board, word, 0))
                    return true;
            }
        }
        return false;


    }
    bool backtrack(int i, int j, vector<vector<char>>& board, string& word, int k) {
        if (k == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[k] != board[i][j]) \
            return false;
        char temp{board[i][j]};
        board[i][j] = '#';
        bool res = false;
        res = res || backtrack(i + 1, j, board, word, k + 1);
        res = res || backtrack(i, j + 1, board, word, k + 1);
        res = res || backtrack(i - 1, j, board, word, k + 1);
        res = res || backtrack(i, j - 1, board, word, k + 1);
        board[i][j] = temp;
        return res;
    }
};
