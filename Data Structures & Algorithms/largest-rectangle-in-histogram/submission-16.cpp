class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res{};
        for (int i{}; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int height{heights[st.top()]};
                int width{};
                st.pop();
                if (st.empty()) width = i;
                else width = i - st.top() - 1;
                res = std::max(res, height * width);
            }
            st.push(i);
        }
        while (!st.empty()) {
                int height{heights[st.top()]};
                int width{};
                st.pop();
                if (st.empty()) width = static_cast<int> (heights.size());
                else width = heights.size() - st.top() - 1;
                res = std::max(res, height * width);
            }

        return res;
    }
};
