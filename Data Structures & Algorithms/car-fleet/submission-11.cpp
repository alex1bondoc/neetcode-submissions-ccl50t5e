class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.begin(), pair.end());
        reverse(pair.begin(), pair.end());
        std::vector<double> st;
        st.push_back((double)(target - pair[0].first) / pair[0].second);
        for (int i{1}; i < pair.size(); ++i) {
            double time {(double)(target - pair[i].first) / pair[i].second};
            if (st.empty() || st.back() < time) {
                st.push_back(time);
            }
        }
        
        
        return st.size();
    }
};