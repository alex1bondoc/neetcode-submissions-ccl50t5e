class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n{static_cast<int>(nums.size() - 1)};
        int slow{n};
        int fast{n};
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        int cp{n};
        do {
            cp = nums[cp];
            slow = nums[slow];
        } while (cp != slow);
        return cp;
    }   
};