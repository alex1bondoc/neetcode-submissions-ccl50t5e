class Solution {
public:
    int rob(vector<int>& nums) {
        auto helper = [&](vector<int>& v){
            int n{static_cast<int> (v.size())};
            int rob1{}, rob2{};
            for (int i{n - 1}; i >= 0; --i) {
                int cur{max(rob1, rob2 + v[i])};
                rob2 = rob1;
                rob1 = cur;
            }
            return max(rob1, rob2);
        };
        vector<int> v1(nums.begin() + 1, nums.end());
        vector<int> v2(nums.begin(), nums.end() - 1);
        return max(nums[0], max(helper(v1), helper(v2)));
    }
};
