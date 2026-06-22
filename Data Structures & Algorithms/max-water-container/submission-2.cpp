class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left{}, right = heights.size() - 1;
        int sol{};
        while (left < right) {
            sol = std::max(sol, std::min(heights[right], heights[left]) * (right - left));
            if (heights[left] > heights[right]){
                right --;
            }
            else {
                left ++;
            }
        }
        return sol;
    }
};
