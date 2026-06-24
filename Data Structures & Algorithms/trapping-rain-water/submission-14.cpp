class Solution {
public:
    int trap(vector<int>& height) {
        std::stack<std::pair<int, int>> st;
        int rain{};
        for (int i = 0; i < height.size(); ++i) {
            while (st.size() > 0 && height[i] >= height[st.top().first]) {
                int mid{height[st.top().first]};
                st.pop();
                if (st.size() > 0) {
                    int right{height[i]};
                    int left{height[st.top().first]};
                    int h{std::min(left, right) - mid};
                    int w{i - st.top().first - 1};
                    rain += w * h;
                }
            }
            st.push({i, height[i]});
        }
        return rain;
    }
};