class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [key, value] : adj) {
            sort(adj[key].rbegin(), adj[key].rend());
        }
        vector<string> res;
        auto hielz = [&](auto& self, string node) -> void {
            while (adj[node].size()) {
                string v{adj[node].back()};
                adj[node].pop_back();
                self(self, v);
            }
            res.push_back(node);
        };
        hielz(hielz, "JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
