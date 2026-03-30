class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res{0}, s{0};
        std::unordered_map<int, int> map{{0, 1}};
        for (const int& num: nums) {
            s += num;
            int dif{s - k};
            res += map[dif];
            map[s] += 1;
        }
        return res;
    }
};