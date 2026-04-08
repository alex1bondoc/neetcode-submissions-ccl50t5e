class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0;
        int jumps{};
        int end = 0;
        if (end == nums.size() - 1) return 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxReach = std::max(maxReach, i + nums[i]);
            if (i == end){
                jumps ++;
                end = maxReach;
            }
            if (end >= nums.size() - 1)
                break ;
        }
        return jumps;
    }
};
