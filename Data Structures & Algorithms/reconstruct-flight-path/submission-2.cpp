class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        std::sort(tickets.begin(), tickets.end());
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        vector<string> res{"JFK"};
        int targetLen{static_cast<int>(tickets.size() + 1)};
        auto dfs = [&](auto self, string node){
            if (res.size() == targetLen) return true;
            if (!adj.contains(node)) return false;
            vector<string> tmp = adj[node];
            for (int i{}; i < tmp.size(); ++i) {
                string v{tmp[i]};
                adj[node].erase(adj[node].begin() + i);
                res.push_back(v);
                if (self(self, v)) return true;
                adj[node].insert(adj[node].begin() + i, v);
                res.pop_back();
            }
            return false;
        };
        dfs(dfs, "JFK");
        return res;
    }
};
