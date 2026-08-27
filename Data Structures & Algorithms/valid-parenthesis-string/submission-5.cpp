class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for (int i{}; i < s.size(); ++i) {
            char c{s[i]};
            if (c == '(') {
                left.push(i);
            }
            else if (c == '*') {
                star.push(i);
            }
            else {
                if (!left.size() && !star.size()) return false;
                if (left.size()) left.pop();
                else star.pop();
            }
        }
        while (left.size() && star.size()) {
            if (left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }
        return left.size() == 0;
    }
};
