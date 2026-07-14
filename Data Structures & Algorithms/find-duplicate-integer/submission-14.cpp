class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow{0};
        int fast{0};
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        int cp{0};
        do {
            cp = nums[cp];
            slow = nums[slow];
        } while (cp != slow);
        return cp;
    }   
};