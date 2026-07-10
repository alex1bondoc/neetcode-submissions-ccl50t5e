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
        for (const auto& num : current) {
            std::cout << num << " ";
        }
        std::cout<< ":" << k << " " << start << std::endl; 
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
                    while (left < right && nums[left] == nums[left - 1]) left++;
                }
                else if (a + b < target){
                    left ++;
                }
                else {
                    right --;
                }
            }
        }
        else {
            for (int i{start}; i < nums.size(); ++i) {
                if (i > start && nums[i] == nums[i - 1]) continue; 
                current.push_back(nums[i]);
                ksum(nums, target - nums[i], k - 1, i + 1);
                current.pop_back();
            }
        }
    }
};