class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast{};
        int slow{};
        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        int slowCopy{};
        while (1) {
            slow = nums[slow];
            slowCopy = nums[slowCopy];
            if (slowCopy == slow) return slow;
        }
    }
};
