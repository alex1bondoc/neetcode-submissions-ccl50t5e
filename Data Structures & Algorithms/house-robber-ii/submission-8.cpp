class Solution {
    unordered_map<int, int> cache;
public:
    int rob(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        auto back = [&](auto self, int i, int end){
            if (i >= end) {
                return 0;
            }
            return max(self(self, i + 1, end), self(self, i + 2, end) + nums[i]);
        };
        return max(back(back, 0, n - 1), back(back, 1, n));
    }
};
