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
            st.push_back(time);
            while (st.size() > 1 && st.back() <= st[st.size() - 2]) {
                st.pop_back();
            }
        }
        return st.size();
    }
};
