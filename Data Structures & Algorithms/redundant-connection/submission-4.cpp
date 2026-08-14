class DSU {
    vector<int> parent;
    int components;
public: 
    DSU(int n): components{n} {
        parent.resize(n + 1);
        for (int i{}; i < n; ++i) {
            parent[i] = i;
        }
    } 
    
    int find(int u) {
        while (u != parent[u]) {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return u;
    }

    bool unionSet(int u, int v) {
        int pu{find(u)}, pv{find(v)};
        if (pu == pv) return false;

        parent[pv] = pu;
        components--;
        return true;
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu{static_cast<int>(edges.size())};
        for (const auto& edge : edges ){
            if (!dsu.unionSet(edge[0], edge[1])) return edge;
        }
        return {};
    }
};
