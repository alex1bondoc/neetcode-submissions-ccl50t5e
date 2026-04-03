class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 0;
        int sufix = 0;
        int res = nums[0];
        for (int i{0}; i < nums.size(); ++i) {
            int num = nums[i];
            int num2 = nums[nums.size() - 1 - i];
            prefix = prefix ? prefix * num : num;
            sufix = sufix ? sufix * num2 : num2;
            res = std::max(res, std::max(sufix, prefix));
        }
        return res;
    }
    
};
