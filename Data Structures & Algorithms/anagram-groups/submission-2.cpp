class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> sol;
        for (auto& str : strs) {
            std::vector<int> counter(26, 0);
            for (char c : str) {
                counter[c - 'a'] ++;
            }
            string key = "";
            for (int i{}; i < 26; ++i) {
                key += ',' + counter[i];
            }
            sol[key].push_back(str);
        }        
        std::vector<std::vector<string>> result;
        for (auto& p: sol) {
            auto [x, vect] = p;
            result.push_back(vect);
        }
        return result;
    }
};
