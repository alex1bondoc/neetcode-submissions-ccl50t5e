class Solution {
public:
    int trap(vector<int>& height) {
        int left{0}, right{static_cast<int>(height.size() - 1)};
        int maxLeft{height[0]}, maxRight{height[height.size() - 1]};
        int res{};
        while (left < right) {
            if (maxLeft < maxRight) {
                left++;
                maxLeft = max(height[left], maxLeft);
                res += maxLeft - height[left];
            }
            else {
                right--;
                maxRight = max(height[right], maxRight);
                res += maxRight - height[right];
            }
        }
        return res;
    }
};