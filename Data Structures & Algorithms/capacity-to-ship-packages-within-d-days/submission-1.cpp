class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum{};
        int maxi{};
        for (const auto& w : weights) {
            sum += w;
            maxi = std::max(maxi, w);
        }
        int left{maxi};
        int right{sum};
        int sol{};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            int d{1};
            sum = 0;
            for (const auto& w : weights) {
                if (sum + w > mid) {
                    d ++;
                    sum = w;
                }
                else sum += w;
            }
            std::cout << d << " " << mid << std::endl;
            if (d <= days) {
                sol = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return sol;
    }
};