class Solution {
public:
    int trap(vector<int>& height) {
        int left{}, right{static_cast<int>(height.size() - 1)};
        int leftMax = height[left];
        int rightMax = height[right];
        int rain{};
        while (left < right) {
            if (leftMax < rightMax) {
                left ++;
                leftMax = std::max(leftMax, height[left]);
                rain += leftMax - height[left];
            }
            else {
                right --;
                rightMax = std::max(rightMax, height[right]);
                rain += rightMax - height[right];
            }
        }
        return rain;
    }
};