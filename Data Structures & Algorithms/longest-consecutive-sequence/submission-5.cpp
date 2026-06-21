class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> map;
        int res = 0;
        for (int x : nums) {
            if (map[x]) continue;
            map[x] = map[x - 1] + map[x + 1] + 1;
            map[x - map[x - 1]] = map[x];
            map[x + map[x + 1]] = map[x];
            res = std::max(res, map[x]);
        }
        return res;
    }
};
