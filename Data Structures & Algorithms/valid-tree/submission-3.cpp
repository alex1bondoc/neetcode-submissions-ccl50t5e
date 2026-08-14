class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({0, -1});
        while (q.size()) {
            auto [node, parent] = q.front();
            q.pop();
            for (int nei : adj[node]) {
                std::cout << node << ' ' << nei << endl;
                if (nei == parent) continue;
                if (visited.contains(nei)) return false;
                visited.insert(nei);
                q.push({nei, node});
            }
        }
        std::cout << visited.size(); 
        return visited.size() + 1 == n;
    }
};
