class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        int cnt = 0;
        for (auto& x : nums) {
            if (m.contains(target - x)) {
                return {m[target - x], cnt};
            }
            m.insert({x, cnt});
            cnt++;
        }
        return {};
    }
};
