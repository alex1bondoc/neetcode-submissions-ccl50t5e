class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        std::stack<int> stack;
        for (int i = 0; i <= heights.size(); ++i) {
            while (!stack.empty() && (i == heights.size() || heights[stack.top()] >= heights[i])) {
                int h = heights[stack.top()];
                stack.pop();
                int w = 0;
                if (stack.empty()) w = i;
                else w = i - stack.top() - 1;
                res = max(res, h * w);
            }
            stack.push(i);
        }
        return res;
    }
};
