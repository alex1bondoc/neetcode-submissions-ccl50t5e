class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n{static_cast<int>(tickets.size()) + 1};
        unordered_map<string, vector<string>> adj;
        sort(tickets.begin(), tickets.end());
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        vector<string> res{"JFK"};
        auto dfs = [&](auto self, string node) -> bool {
            if (res.size() == n) return true;
            if (adj[node].size() == 0) return false;
            for (int i{}; i < adj[node].size(); ++i) {
                string v{adj[node][i]};
                adj[node].erase(adj[node].begin() + i);
                res.push_back(v);
                if (self(self, v)) return true;
                res.pop_back();
                adj[node].insert(adj[node].begin() + i, v);
            }
            return false;
        };
        dfs(dfs, "JFK");
        return res;
    }
};
