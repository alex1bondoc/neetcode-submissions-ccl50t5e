class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res{};
        for (int i{}; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int height{heights[st.top()]};
                st.pop();
                int width{i};
                if (!st.empty()) width = i - st.top() - 1;
                res = std::max(res, width * height);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int height{heights[st.top()]};
            st.pop();
            int width{static_cast<int>(heights.size())};
            if (!st.empty()) width = heights.size() - st.top() - 1;
            res = std::max(res, width * height);
        }
        return res;
    }
};
