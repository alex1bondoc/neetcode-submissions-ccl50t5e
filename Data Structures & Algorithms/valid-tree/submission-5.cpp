class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) return false;
        vector<int> parent(n), size(n);
        int comps{n};
        for(int i{}; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
        auto find = [&](int node){
            while (parent[node] == node) {
                parent[node] = parent[parent[node]];
            }
            return parent[node];
        };
        for (const auto& edge : edges) {
            int u{find(edge[0])}, v{find(edge[1])};
            if (u == v) return false;
            if (size[u] < size[v]) {
                swap(u, v);
            }
            comps--;
            size[u] += size[v];
            parent[v] = u;
        }
        return comps == 1;
    }
};
