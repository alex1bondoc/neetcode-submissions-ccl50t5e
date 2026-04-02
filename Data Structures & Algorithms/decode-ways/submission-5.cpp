class Solution {
private:
    std::unordered_map<string, int> cache;
public:
    int numDecodings(string s) {
        if (s.size() == 0){
            return 1;
        }
        if(s[0] == '0') return 0;
        if (cache.contains(s))
            return cache[s];
        int res = numDecodings(s.substr(1));
        if (s.size() >= 2) {
            if ((s[0] == '1') || (s[0] == '2' && s[1] < '7')){
                res += numDecodings(s.substr(2));
            }
        }
        cache[s] = res;
        return res;
    }
};
