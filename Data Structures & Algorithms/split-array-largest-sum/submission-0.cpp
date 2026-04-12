class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int res = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            int curSum = 0;
            int subarray = 1;
            for (int num : nums) {
                curSum += num;
                if (curSum >  mid) {
                    subarray++;
                    curSum = num;
                }
            }
            if (subarray > k) {
                l = mid + 1;

            }
            else {
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
};