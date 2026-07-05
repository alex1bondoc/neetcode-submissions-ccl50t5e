class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Folosim deque pentru a putea șterge/accesa de la ambele capete
        deque<int> dq;
        vector<int> solution;
        int right{};
        int left{};
        while (right < nums.size()) {
            if (right >= k) {
                left++;
                if (dq.front() < left) dq.pop_front();
            }
            while (dq.size() && nums[right] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(right);
            if (right >= k - 1)
                solution.push_back(nums[dq.front()]);
        
            right++;
        }
        return solution;
    }
};