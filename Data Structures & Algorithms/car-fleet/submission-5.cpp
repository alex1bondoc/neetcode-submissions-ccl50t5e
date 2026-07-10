class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        std::sort(pair.rbegin(), pair.rend());
        int fleet = 1;
        double time = (target - pair[0].first) *1.0/ pair[0].second;
        std::stack<double> timers;
        timers.push(time);
        for (int i{1}; i < pair.size(); ++i) {
            double t{(target - pair[i].first) * 1.0 / pair[i].second}; 
            while (!timers.empty() && timers.top() >= t) {
                timers.pop();
            }
            timers.push(t);
        }
        return timers.size();
    }
};
