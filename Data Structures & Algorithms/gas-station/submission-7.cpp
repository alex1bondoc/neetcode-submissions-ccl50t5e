class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int currentTank = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            int netGas = gas[i] - cost[i];

            totalGas += netGas;
            currentTank += netGas;

            if (currentTank < 0) {
                start = i + 1;
                currentTank = 0;
            }
        }

        if (totalGas < 0) {
            return -1;
        }

        return start;
    }
};
