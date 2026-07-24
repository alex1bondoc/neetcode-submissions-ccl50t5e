class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int res{};
        for (const auto& num : nums) {
            if (!map[num]) {
                map[num] = map[num - 1] + map[num + 1] + 1;
                map[num - map[num - 1]] = map[num];
                map[num + map[num + 1]] = map[num];
                res = max(res, map[num]);
            }

        }
        return res;
    }
};
