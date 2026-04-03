class Solution {
private:
    unordered_map<int, bool> cache;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dp(s, wordDict, 0);
    }
    bool dp(string& s, vector<string>& wordDict, int i) {
        std::cout<<s<<"\n";
        if (i == s.size()){
            return true;
        }
        if (cache.find(i) != cache.end()) {
            return cache[i];
        }
        bool res = false;
        for (auto word : wordDict) {
            if (word == s.substr(i, word.size())){
                res = res || dp(s, wordDict, i + word.size());
        
            }
        }
        cache[i] = res;
        return cache[i];
    }
};
