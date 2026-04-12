class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        std::unordered_set<int> s;
        for (right = 0; right < k; ++right) {
            if (s.count(nums[right])) return true;
            s.insert(nums[right]);
        }
        while (right < nums.size()) {
            if (right - left >  k) {
                s.erase(nums[left]);
                left ++;
            }
            if (s.count(nums[right])) return true;
            s.insert(nums[right]);
            right++;
        }
        return false;
    }
};