class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> newNums{1};
        for (const auto& num : nums) {
            newNums.push_back(num);
        }
        nums = newNums;
        nums.push_back(1);
        int n{static_cast<int>(nums.size())};
        auto back = [&](auto self, int i, int j, auto v) {
            if (i == j) return v[i];
            int res{};
            for (int k{i}; k <= j; ++k) {
                vector<int> a(v.begin(), v.begin() + k );
                vector<int> b(v.begin() + k + 1, v.end());
                for (const auto& n : b) {
                    a.push_back(n);
                }
                res = max(res, v[k] * v[k - 1] * v[k + 1] + self(self, 1, a.size() - 2, a));
            }
            
            return res;
        };
        return back(back, 1, n - 2, nums);
    }
};
