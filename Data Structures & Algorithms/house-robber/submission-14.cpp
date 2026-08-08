class Solution {
    unordered_map<int, int> cache;
public:
    int rob(vector<int>& nums) {
        auto back = [&](auto& self, int i){
            if (i >= nums.size()) {
                return 0;
            }
            if (!cache.contains(i))
                cache[i] = max(self(self, i + 1), nums[i] + self(self, i + 2));
            return cache[i]; 
        };

        return back(back, 0);
    }
};
