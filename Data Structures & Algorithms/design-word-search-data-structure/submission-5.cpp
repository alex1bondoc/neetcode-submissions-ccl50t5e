class Node{
public:
    unordered_map<char, Node*> map{};
    bool end{false};

};

class WordDictionary {
    Node* node;
public:
    WordDictionary() : node{new Node()}{
    }
    
    void addWord(string word) {
        auto cur{node};
        for (const auto& c : word) {
            if (!cur->map.contains(c)) cur->map[c] = new Node();
            cur = cur->map[c];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        auto dfs = [&word](auto self, Node* cur, int i) {
            if (i == word.size()) return cur->end;
            if (word[i] == '.') {
                for (const auto& p : cur->map) {
                    auto [key, value] = p;
                    if (self(self, cur->map[key], i + 1)) return true;
                }
                return false;
            }
            else {
                if (!cur->map.contains(word[i])) return false;
                return self(self, cur->map[word[i]], i + 1);
            }
        };
        return dfs(dfs, node, 0);
    }
};
