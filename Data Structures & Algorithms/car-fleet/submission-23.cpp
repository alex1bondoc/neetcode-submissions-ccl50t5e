class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i{0uz}; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }
        std::sort(cars.rbegin(), cars.rend());

        vector<double> st;
        for (const auto& car : cars) {
            double time{(double) (target - car.first) / car.second};
            if (!st.size() || time > st.back()) st.push_back(time);
        }
        return st.size();
    }
};
