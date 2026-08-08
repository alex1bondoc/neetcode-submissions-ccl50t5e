class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int finish{numCourses};
        vector<int> in(finish);
        unordered_map<int, vector<int>> adj;
        for (const auto pre : prerequisites) {
            if (!adj.contains(pre[1])) {
                adj[pre[1]] = {};
            }
            adj[pre[1]].push_back(pre[0]);
            in[pre[0]]++;
        }
        queue<int> q;
        vector<int> res;
        for (int i{}; i < numCourses; ++i) {
            if (in[i] == 0) q.push(i);
        }
        while (q.size()) {
            finish--;
            int node{q.front()};
            q.pop();
            res.push_back(node);
            for (int neigh : adj[node]) {
                in[neigh]--;
                if (in[neigh] == 0) q.push(neigh);
            }
        }
        if (finish != 0) return {};
        return res;
    }
};
