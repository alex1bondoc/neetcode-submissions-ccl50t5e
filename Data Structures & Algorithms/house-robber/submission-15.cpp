class Solution {
    unordered_map<int, int> cache;
public:
    int rob(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        cache[n] = cache[n + 1] = 0;
        n--;
        while (n >= 0) {
            cache[n] = max(cache[n + 1], cache[n + 2] + nums[n]);
            n--;
        }
        return cache[0];
    }
};
