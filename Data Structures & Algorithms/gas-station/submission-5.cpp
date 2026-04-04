class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = reduce(gas.begin(), gas.end(), 0);
        int sum2 = reduce(cost.begin(), cost.end(), 0);
        if (sum2 >  sum){
            return -1;
        }
        int res = 0;
        int acc{};
        for (int i = 0; i < gas.size(); ++i) {
            if (gas[i] + acc < cost[i]) {
                res = (i + 1) % gas.size();
                acc = 0;
            }
            else {
                acc += gas[i] - cost[i];
            }
        }
        return res;
    }
};
