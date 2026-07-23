class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n{static_cast<int>(nums.size())};
        for (int i{}; i < n; ++i) {
            if (map.contains(target - nums[i])) {
                return {map[target - nums[i]], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};