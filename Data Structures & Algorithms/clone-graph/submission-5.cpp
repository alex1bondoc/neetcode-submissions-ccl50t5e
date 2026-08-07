/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> map;
        unordered_set<Node*> visited;
        queue<Node*> q;
        map[node] = new Node(node->val);
        q.push(node);
        visited.insert(node);
        while (q.size()) {
            auto n = q.front();
            q.pop();
            for (const auto neighbor : n->neighbors) {
                if (!map.contains(neighbor)) {
                    map[neighbor] = new Node(neighbor->val);
                }
                map[n]->neighbors.push_back(map[neighbor]);
                if (!visited.contains(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return map[node];
    }
};
