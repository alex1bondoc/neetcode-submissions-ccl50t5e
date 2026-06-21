class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;
        int cnt = 0;
        for (int x : nums) {
            sum += x;
            int remaining = sum - k;
            cnt += map[remaining];
            map[sum]++;
        }
        return cnt;
    }
};