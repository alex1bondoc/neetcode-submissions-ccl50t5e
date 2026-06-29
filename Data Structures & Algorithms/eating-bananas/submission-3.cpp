class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int sol{};
        int left{1};
        int maxi{0};
        for (const auto& p : piles) {
            maxi = std::max(maxi, p);
        }
        int right{maxi};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            int hours{};
            for (const auto& p : piles) {
                hours += p / mid;
                hours += ((p % mid != 0) ? 1 : 0);
            }
            if (hours > h) {
                left = mid + 1;
            }
            else {
                sol = mid;
                right = mid - 1;
            }
        }
        return sol;
    }
};
