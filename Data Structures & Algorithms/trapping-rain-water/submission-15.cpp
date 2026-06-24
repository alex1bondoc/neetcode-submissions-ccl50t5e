class Solution {
public:
    int trap(vector<int>& height) {
        std::stack<int> st;
        int rain{};
        for (int i{}; i < height.size(); ++i) {
            while (st.size() > 0 && height[i] >= height[st.top()]) {
                int mid{height[st.top()]};
                st.pop();
                if (st.size() > 0) {
                    int left{height[st.top()]};
                    int right{height[i]};
                    int h{std::min(left, right) - mid};
                    int w{i - st.top() -1};
                    rain += h * w;
                }
            }
            st.push(i);
        }

        return rain;
    }
};