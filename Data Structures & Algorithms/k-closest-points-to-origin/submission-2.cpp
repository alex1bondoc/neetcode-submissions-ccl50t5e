class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int, vector<int>>> pq;
        for (const auto& point : points) {
            pq.push({point[0] * point[0] + point[1] * point[1], point});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (pq.size()) {
            const auto [x, vect] = pq.top();
            res.push_back(vect);
            pq.pop();
        }

        return res;
    }
};
