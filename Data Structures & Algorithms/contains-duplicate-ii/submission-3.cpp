class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> control;
        for (int i{}; i < k && i < nums.size(); ++i) {
            std::cout << 1<< endl;
            if (control.contains(nums[i])) return true;
            control.insert(nums[i]);
        }
        int left{0};
        int right{k};
        for (; right < nums.size(); right++, left++) {
            if (control.contains(nums[right])) return true;
            control.insert(nums[right]);
            control.erase(nums[left]);

        }
        return false;
    }
};