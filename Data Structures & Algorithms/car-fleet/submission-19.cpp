class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        for (int i{}; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }
        std::sort(cars.begin(), cars.end(), [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return p1.first > p2.first;
        });
        int cur_time{};
        int fleets{};
        for (const auto& car : cars) {
            double time{(double)(target - car.first) / car.second};
            if (time > cur_time) {
                cur_time = time;
                fleets ++;
            }
        }
        return fleets;
    }
};
