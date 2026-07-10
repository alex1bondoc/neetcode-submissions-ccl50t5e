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
        std::vector<int> sol;
        for (const auto& car : cars) {
            double time{(double) (target - car.first) / car.second};
            sol.push_back(time);
            while (sol.size() > 1 && sol[sol.size() - 1] <= sol[sol.size() - 2]) sol.pop_back();
        }
        return sol.size();
    }
};
