class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> parent(points.size());
       // for (int i{}; i < points.size(); ++i) {
       //     parent[i] = i;
       // }
        auto distance = [&](vector<int>& x, vector<int>& y) {
            return abs(x[0] - y[0]) + abs(x[1] - y[1]);
        };
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        int cost{0};
        while (pq.size()) {
            auto [price, node] = pq.top();
            pq.pop();
            if(parent[node] == 1) continue;
            cost += price;
            parent[node] = 1;
            for (int i{}; i < points.size(); ++i) {
                if (!parent[i] && i != node) {
                    pq.push({distance(points[i], points[node]), i});
                }
            }
        }
        return cost;
    }
};
