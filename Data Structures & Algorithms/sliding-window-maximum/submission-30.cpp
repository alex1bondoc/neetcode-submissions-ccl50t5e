class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        vector<int> res;
        int left{};
        for (int right{}; right < nums.size(); ++right) {
            while (dq.size() && dq.front().first < left) {
                dq.pop_front();
            }
            while (dq.size() && dq.back().second < nums[right]) {
                dq.pop_back();
            }
            dq.push_back({right, nums[right]});
            if (right >= k - 1) {
                res.push_back(dq.front().second);
                left++;
            }
        }
        return res;
    }
};