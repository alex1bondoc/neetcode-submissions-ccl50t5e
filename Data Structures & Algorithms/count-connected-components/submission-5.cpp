class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> rank(n, 1);
        vector<int> parent(n, 0);
        for (int i{}; i < n; ++i) {
            parent[i] = i;
        }
        int res = n;
        for(const auto& edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            while (n1 != parent[n1]) {
                parent[n1] = parent[parent[n1]];
                n1 = parent[n1];
            }
            while (n2 != parent[n2]) {
                parent[n2] = parent[parent[n2]];

                n2 = parent[n2];
            }
            if (n1 == n2) {
                continue;
            }
            res --;
            if (rank[n1] > rank[n2]) {
                std::swap(n1, n2);
            }
            parent[n1] = n2;
            rank[n2] += rank[n1];
        }
        return res;
    }
};
