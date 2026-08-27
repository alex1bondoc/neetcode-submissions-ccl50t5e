class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total{};
        int gasa{};
        int res{};
        for (int i{}; i < gas.size(); ++i) {
            gasa += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            if (gasa < 0) {
                res = i + 1;
                gasa = 0;
            }
        }
        if (total < 0) return -1;
        return res;
    }
};
