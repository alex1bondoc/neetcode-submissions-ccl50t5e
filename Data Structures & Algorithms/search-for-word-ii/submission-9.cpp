class Node{
    
public:
    unordered_map<char, Node*> map;
    bool end;
    bool count;
    bool visited;
    Node(bool end) {
        this->end = end;
        this->count = 0;
        this->visited = 0;
    }
};

class PrefixTree {
    
public:
    Node* node;
    PrefixTree() {
        this->node = new Node(false);
    }
    
    void insert(string word) {
        auto* cur{this->node};
        for (const auto& c : word) {
            if (!cur->map.contains(c)) {
                cur->map[c] = new Node(false);
            }
            cur = cur->map[c];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        auto* cur{this->node};
        for (const auto& c : word) {
            if (!cur->map.contains(c)) return false;
            cur = cur->map[c];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        auto* cur{this->node};
        for (const auto& c : prefix) {
            if (!cur->map.contains(c)) return false;
            cur = cur->map[c];
        }
        return true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree pt;
        vector<string> sol;
        for (auto word : words) {
            pt.insert(word);
        }
        auto back = [&sol, &board](auto back, Node* node, int i, int j, string word) {
            if (i < 0 || j < 0 || 
            i >= board.size() || j >= board[0].size() ||
            !node->map.contains(board[i][j]) || node->visited) return;
            word += board[i][j];
            
            auto* parent{node};
            node = node->map[board[i][j]];
            
            if (node->end && node->count == 0) {
                sol.push_back(word);
                node->count = 1;
            }
            char help{board[i][j]};
            board[i][j] = '#';
            back(back, node, i + 1, j, word);
            back(back, node, i, j + 1, word);
            back(back, node, i - 1, j, word);
            back(back, node, i, j - 1, word);
            board[i][j] = help;

        };
        for (int i{}; i < board.size(); ++i) {
            for (int j{}; j < board[0].size(); ++j) {

                back(back, pt.node, i, j, "");
            }
        }
        return sol;
    }
};
