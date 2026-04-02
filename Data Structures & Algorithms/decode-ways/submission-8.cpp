class Solution {
private:
    std::unordered_map<string, int> cache;
public:
    int numDecodings(string s) {
        if (s.size() == 0){
            return 1;
        }
        if (cache.contains(s)){
            return cache[s];
        }
        if (s.size() == 1) {
            if (s[0] == '0')
                return 0;
            cache[s] = numDecodings(s.substr(1));
            return cache[s];
        }
        if (s[0] == '0')
            return 0;
        if (s[0] == '1' || (s[0] == '2' && s[1] < '7'))
            cache[s] = numDecodings(s.substr(1)) + numDecodings(s.substr(2));
        else
            cache[s] = numDecodings(s.substr(1));
        return cache[s];
    }
};
