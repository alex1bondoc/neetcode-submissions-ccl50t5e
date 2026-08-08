class Solution {
public:
    int rob(vector<int>& nums) {
        auto back = [&](auto& self, int i){
            if (i >= nums.size()) {
                return 0;
            }
            return max(self(self, i + 1), nums[i] + self(self, i + 2));
        };

        return back(back, 0);
    }
};
