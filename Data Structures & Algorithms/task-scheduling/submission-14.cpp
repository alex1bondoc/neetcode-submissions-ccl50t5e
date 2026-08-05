class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;
        for (const auto& c : tasks) {
            count[c] ++;
        }
        priority_queue<int> pq;
        for (const auto& p : count) {
            auto [key, value] = p;
            pq.push(value);
        }
        queue<pair<int, int>> q;
        int time{};
        while (q.size() || pq.size()) {
            time++;
            if (pq.empty()) {
                time = q.front().second;
            }
            else {
                int cnt{pq.top() - 1};
                pq.pop();
                if (cnt) q.push({cnt, time + n});
            }
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
