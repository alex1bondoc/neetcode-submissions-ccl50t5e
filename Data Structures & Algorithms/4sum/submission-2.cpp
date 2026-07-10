class Solution {
    std::vector<std::vector<int>> solution;
    std::vector<int> current;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        ksum(nums, target, 4, 0);
        return solution;
    }
    void ksum(vector<int>& nums, int target, int k, int start) {
        if (k == 2) {
            int left = start;
            int right = nums.size() - 1;
            while (left < right) {
                int a{nums[left]}, b{nums[right]};
                if (a + b == target) {
                        current.push_back(a);
                        current.push_back(b);
                        solution.push_back(current);
                        current.pop_back();
                        current.pop_back();
                    left ++;
                    right --;
                    while (nums[left - 1] != a) left ++;
                    while (right != nums.size() - 1 && nums[right + 1] != b) right --;
                }
                else if (a + b > target){
                    left ++;
                    while (nums[left - 1] != a) left ++;
                }
                else {
                    right --;
                    while (right != nums.size() - 1 && nums[right + 1] != b) right --;
                }
            }
        }
        else {
            for (int i{start}; i < nums.size(); ++i) {
                current.push_back(nums[start]);
                ksum(nums, target - nums[start], k - 1, i + 1);
                current.pop_back();
            } 
        }
    }
};