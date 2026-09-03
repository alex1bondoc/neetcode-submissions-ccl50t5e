class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n{static_cast<int>(temperatures.size())};
        vector<int> res(n);
        for (int i{}; i < n; ++i) {
            auto temp{temperatures[i]};
            while (st.size() && temp > st.top().second) {
                auto [idx, t]{st.top()};
                st.pop();
                res[idx] = i - idx;
            }
            st.push({i, temp});
        }
        return res;
    }
};
