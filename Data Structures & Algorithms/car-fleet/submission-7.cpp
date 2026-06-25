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
        for(auto p : pair) {
            st.push_back((double)(target - p.first) / p.second);
            while (st.size() > 1 && st.back() <= st[st.size()- 2])
                st.pop_back(); 
        }
        return st.size();
    }
};