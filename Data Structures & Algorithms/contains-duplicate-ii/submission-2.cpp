class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, bool> control;
        for (int i{}; i < k && i < nums.size(); ++i) {
            std::cout << 1<< endl;
            if (control[nums[i]]) return true;
            control[nums[i]] = true;
        }
        int left{0};
        int right{k};
        for (; right < nums.size(); right++, left++) {
            if (control[nums[right]]) return true;
            control[nums[right]] = true;
            control[nums[left]] = false;

        }
        return false;
    }
};