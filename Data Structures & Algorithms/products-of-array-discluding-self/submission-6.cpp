class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 1);
        vector<int> sufix(n + 1, 1);
        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            sufix[i] = sufix[i + 1] * nums[i + 1];
        }
        vector<int> sol;
        for (int i = 0; i < n; ++i) {
            sol.push_back(prefix[i] * sufix[i]);
        }
        return sol;
   }
};
