class DSU {
private:
    vector<int> parent, size;
    int comps;
public:
    DSU(int n): comps{n} {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i{}; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        while (node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    void unionSet(int u, int v) {
        int pu{find(u)}, pv{find(v)};
        if (parent[pv] == parent[pu]) return;
        if (size[pv] > size[pu]) {
            swap(pv, pu);
        }
        parent[pv] = pu;
        size[pu] += size[pv];
        comps--;
    }

    int getComps() {
        return comps;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu{n};
        for (const auto& edge : edges) {
            dsu.unionSet(edge[0], edge[1]);

        }
        return dsu.getComps();
    }
};
