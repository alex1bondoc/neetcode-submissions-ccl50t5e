class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = 0;
        int mini = 10001;
        for (int x : prices) {
            if (x < mini) {
                mini = x;
            }
            else {
                s += x - mini;
                mini = x;
            }
        }
        return s;
    }
};