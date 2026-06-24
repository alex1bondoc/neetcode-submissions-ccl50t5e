class Solution {
public:
    int trap(vector<int>& height) {
        int n{static_cast<int>(height.size())};
        std::vector<int> left(n, 0);
        std::vector<int> right(n, 0);
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i{1}; i < n; ++i) {
            left[i] = std::max(left[i - 1], height[i]);
            right[n - i - 1] = std::max(right[n - i], height[n - i - 1]);
        }
        int rain{};
        for (int i = 0; i < n; ++i) {
            rain += (std::min(left[i], right[i]) - height[i]); 
        }
        return rain;
    }
};