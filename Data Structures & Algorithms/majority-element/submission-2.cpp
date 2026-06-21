class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = nums[0];
        int app = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == cand) {
                app ++;
            }
            else {
                app --;
                if (app < 0) cand = nums[i];
            }
        }
        return cand;
    }
};