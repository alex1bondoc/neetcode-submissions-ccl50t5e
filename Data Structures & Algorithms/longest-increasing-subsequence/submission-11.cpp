class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp;
        auto binarySearch = [&](int search) {
            int l{0}, r = dp.size() - 1;
            int pos{};
            while (l <= r) {
                int mid{l + (r - l) / 2};
                if (dp[mid] >= search) {
                    r = mid - 1;
                    pos = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            return pos;
        };
        for (int x: nums) {
            if (dp.empty() || dp.back() < x) {
                dp.push_back(x);
            }
            else {
                std::cout << binarySearch(x) << " " << x<< endl;
                dp[binarySearch(x)] = x;
            }
        }
        return dp.size();
    }
};