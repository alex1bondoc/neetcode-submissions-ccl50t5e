class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n{static_cast<int>(heights.size())};
        int res{};
        stack<pair<int, int>> st;

        for (int i{}; i < n; ++i) {
            int h{heights[i]};
            int start{i};
            while (st.size() && st.top().second > h) {
                auto [idx, height]{st.top()};
                st.pop();
                res = max(res, height * (i - idx));
                start = idx;
            }
            st.push({start, h});
        }
        while (st.size()) {
            auto [idx, height]{st.top()};
            st.pop();
            res = max(res, height * (n - idx));
        }

        return res;
    }
};
