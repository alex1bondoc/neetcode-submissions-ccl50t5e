class Node{
public:
    unordered_map<char, Node*> map{};
    bool end{false};
    bool count{false};

    void addWord(const string word) {
        auto cur{this};
        for (const auto& c :  word) {
            if (!cur->map.contains(c)) cur->map[c] = new Node;
            cur = cur->map[c];
        }
        cur->end = true;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* node{new Node};
        for (const auto& str : words) {
            node->addWord(str);
        }
        vector<string> sol{};
        auto backtrack = [&board, &sol](auto self, string word, int i, int j, Node* node) {
            if (i >= board.size() || j >= board[0].size() ||
            i < 0 && j < 0 || node == nullptr) return;
            char temp{board[i][j]};

            node = node->map[temp];
            word += temp;
            if (node && node->end && node->count == false) { 
                sol.push_back(word);
                node->count = true;
            }
            board[i][j] = '#';
            self(self, word, i + 1, j, node);
            self(self, word, i - 1, j, node);
            self(self, word, i, j + 1, node);
            self(self, word, i, j - 1, node);
            
            board[i][j] = temp;
        };
        for (int i{}; i < board.size(); ++i) {
            for (int j{}; j < board[0].size(); ++j) {
                backtrack(backtrack, "", i, j, node);
            }
        }
        return sol;
    }

};
