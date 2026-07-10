class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        for (int i{0}; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }
        std::sort(cars.begin(), cars.end(), [](const auto& pair1, const auto& pair2) {
            return pair1.first > pair2.first;
        });
        std::stack<double> st;
        for (const auto& car : cars) {
            double time{(double)(target - car.first) / car.second};
            while (st.size() && st.top() >= time) {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};