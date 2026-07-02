class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left{std::max_element(nums.begin(), nums.end())[0]};
        int right{std::accumulate(nums.begin(), nums.end(), 0)};
        int sol{1 << 30};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            int subs{1};
            int sum{};
            for (const auto& num : nums) {
                if (sum + num > mid) {
                    subs++;
                    sum = num;
                }
                else sum += num;
                if (subs > k) break;
            }
            if (subs <= k) {
                sol = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return sol;
    }
};