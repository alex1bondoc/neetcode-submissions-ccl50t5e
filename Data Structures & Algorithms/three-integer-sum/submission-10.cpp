class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> solution;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int a{nums[i]};
            int left{i + 1};
            int right = nums.size() - 1;
            while (left < right) {
                int b{nums[left]}, c{nums[right]};
                if (a + b + c == 0) {
                    solution.push_back({a, b, c});
                    left ++;
                    right --;
                }
                else if (a + b + c > 0) {
                    right -- ;
                }
                else {
                    left ++;
                }
                while (right != nums.size() - 1 && nums[right] == nums[right + 1] && left < right) right --;
                while (nums[left] == nums[left - 1] && left < right) left ++;
            }
        }
        return solution;
    }
};
