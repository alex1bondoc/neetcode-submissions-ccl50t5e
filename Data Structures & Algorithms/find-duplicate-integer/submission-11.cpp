class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int jmp{nums[nums.size() - 1]};
        while (nums[jmp - 1]) {
            int x{nums[jmp - 1]};
            nums[jmp - 1] = 0;
            jmp = x;
        }
        return jmp;
    }   
};