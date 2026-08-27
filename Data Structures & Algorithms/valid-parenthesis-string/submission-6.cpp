class Solution {
public:
    bool checkValidString(string s) {
        int open{}, closed{};
        for (char c : s) {
            if (c == '(') {
                open ++;
                closed++;
            }
            else if (c == '*') {
                open ++;
                closed --;
            }
            else {
                open --;
                closed--;
            }
            if (closed < 0) closed = 0;
            if (open < 0) return false;
        }
        return closed == 0;
    }
};
