class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        const auto& v = mp[key];
        int left{};
        int right{static_cast<int> (v.size() - 1)};
        string sol{};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            const auto& [ts, state] = v[mid];
            if (ts <= timestamp) {
                sol = state;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return sol;
    }
};
