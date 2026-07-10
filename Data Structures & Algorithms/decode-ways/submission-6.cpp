class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0){
            return 1;
        }
        if (s.size() == 1) {
            if (s[0] == '0')
                return 0;
            return numDecodings(s.substr(1));
        }
        if (s[0] == '0')
            return 0;
        return numDecodings(s.substr(1)) + numDecodings(s.substr(2));
    }
};
