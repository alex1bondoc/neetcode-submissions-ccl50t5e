class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), node = 0;
        vector<int> dist(n, 100000000);
        vector<bool> visit(n, false);
        int edges = 0, res = 0;
        dist[0] = 0;
        visit[0] = true;
        while (edges < n - 1) {
            int nextNode{-1};
            for (int i{}; i < n; ++i) {
                if (i == node || visit[i]) continue;
                dist[i] = min(dist[i], manhattan(points[node], points[i]));
                if (nextNode == -1 || dist[i] < dist[nextNode]) {
                    nextNode = i;
                }
            }
            res += dist[nextNode];
            visit[nextNode] = true;
            edges++;
            node = nextNode;
        }
        return res;
    }
private:
    int manhattan(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};