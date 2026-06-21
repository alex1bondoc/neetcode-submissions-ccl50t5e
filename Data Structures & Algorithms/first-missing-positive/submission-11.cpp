class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) nums[i] = 0;
            maxi = std::max(maxi, nums[i]);
        }
        vector<int> v(maxi + 1, 0);
        for (int x : nums) {
            if (!v[x]) { 
                if (x == 0) {
                    v[x] = -nums.size();
                }
                else {
                    v[x] = -x;
                }
            }
        }
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] == 0) return i; 
        }
        return v.size();
    }
};