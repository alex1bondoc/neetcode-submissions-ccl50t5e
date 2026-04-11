class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = std::accumulate(weights.begin(), weights.end(), 0);
        int n = weights.size();
        int left = 0;
        for (int i = 0; i < n; ++i) {
            if (weights[i] > left) {
                left = weights[i];
            }
        }
        int right = sum;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int curShip = 0;
            int curDays = 1;
            for (int i = 0; i < n; ++i) {
                if (curShip + weights[i] <= mid) {
                    curShip += weights[i];
                }
                else {
                    curDays ++;
                    curShip = weights[i];
                }
            }
            cout << curDays << " " << mid <<endl;
            if (curDays <= days) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};