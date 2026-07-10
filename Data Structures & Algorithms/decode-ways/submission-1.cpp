class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0){
            return 1;
        }
        if (s.size() == 1) {
            return 1;
        }
        if (s.size() >= 2) {
            if (s[0] == '0')
                return 0;
            if (s[1] == '0'){
                return 1 + numDecodings(s.substr(2));
            }
            else {
                return numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            }
        }
    }
};
