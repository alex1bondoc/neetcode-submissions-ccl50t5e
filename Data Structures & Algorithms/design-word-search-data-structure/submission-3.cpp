class Node{
public:
    unordered_map<char, Node*> map;
    bool end = false;
    Node() {}
};

class WordDictionary {
    Node* node;
public:
    WordDictionary() {
        node = new Node();
    }
    
    void addWord(string word) {
        auto* cur{node};
        for (const auto& c : word) {
            if (!cur->map.contains(c)) {
                cur->map[c] = new Node();
            }
            cur = cur->map[c];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        auto dfs = [](Node* node, int i, string word, auto dfs) {
            if (i == word.size()) return true;
            auto* cur{node};
            if (word[i] == '.') {
                for (const auto& p : cur->map) {
                    auto [key, val] = p;
                    if (dfs(val, i + 1, word, dfs)) return true;
                }
                return false;
            }
            else {
                if (!node->map.contains(word[i])) return false;
                return dfs(node->map[word[i]], i + 1, word, dfs);
            }
        };
        return dfs(node, 0, word, dfs);
    }
};
