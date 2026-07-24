class Node{
    
public:
    unordered_map<char, Node*> map;
    bool end;
    Node(bool end) {
        this->end = end;
    }
};

class PrefixTree {
    Node* node{};
public:
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
