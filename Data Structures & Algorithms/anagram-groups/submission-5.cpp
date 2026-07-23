class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const auto& str : strs) {
            vector<int> freq(26, 0);
            for (const auto& c : str) {
                freq[c - 'a'] ++;
            }
            string key{to_string(freq[0])};
            for (int i{1}; i < 26; ++i) {
                key += "," + to_string(freq[i]);
            }
            if (map.contains(key)) map[key].push_back(str);
            else map[key] = {str};
        }
        vector<vector<string>> res;
        for (const auto& p : map) {
            auto [key, value] = p;
            res.push_back(value);
        }  
        return res;
    }
};