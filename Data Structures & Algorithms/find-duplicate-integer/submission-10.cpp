class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int jmp{nums[nums.size() - 1]};
        while (nums[jmp]) {
            int x{nums[jmp]};
            nums[jmp] = 0;
            jmp = x;
        }
        return jmp;
    }   
};