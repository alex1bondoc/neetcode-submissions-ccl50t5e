class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> res;
        std::deque<int> d;
        int l = 0;
        int r = 0;
        while (r < n) {
            while(!d.empty() && nums[r] > nums[d.back()]){
                d.pop_back();
            }
            d.push_back(r);
            if (l > d.front()) {
                d.pop_front();
            }
            if (r + 1 >= k) {
                res.push_back(nums[d.front()]);
                l++; 
            }
            r ++;
        }
        return res;
    }
};
