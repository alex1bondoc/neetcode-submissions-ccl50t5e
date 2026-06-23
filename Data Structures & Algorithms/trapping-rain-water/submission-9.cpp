class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = height[left];
        int maxRight = height[right];
        int rain = 0;
        while (left < right) {
            if (maxLeft < maxRight) {
                left ++;
                maxLeft = std::max(maxLeft, height[left]);
                rain += maxLeft - height[left];
            }
            else {
                right --;
                maxRight = std::max(maxRight, height[right]);
                rain += maxRight - height[right];
            }
        }
        return rain;
    }
};
