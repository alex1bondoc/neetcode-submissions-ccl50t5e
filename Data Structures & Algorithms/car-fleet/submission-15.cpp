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
        std::vector<double> st;
        for (const auto& car : cars) {
            double time{(double)(target - car.first) / car.second};
            st.push_back(time);
            while (st.size() > 1 && st.back() <= st[st.size() - 2]) {
                st.pop_back();
            }
        }
        return st.size();
    }
};
// 4 2 0
// 1 3 2
// 6 time
// 