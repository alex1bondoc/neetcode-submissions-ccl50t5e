class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n{static_cast<int>(nums.size() - 1)};
        int slow{n};
        int fast{nums[n]};
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        return slow;
    }   
};