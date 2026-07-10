class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i{0uz}; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }
        std::sort(cars.rbegin(), cars.rend());

        int fleets{};
        int maxTime{};
        for (const auto& car : cars) {
            double time{(double) (target - car.first) / car.second};
            if (time > maxTime) {
                fleets ++;
                maxTime = time;
            }
        }
        return fleets;
    }
};
