class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;
        int i{};
        for (char c : s) {
            if (c == '(') {
                open.push(i);
            }
            else if (c == '*') {
                star.push(i);
            }
            else {
                if (!star.size() && !open.size()) return false;
                if (open.size()) open.pop();
                else star.pop();
            }
            i++;
        }
        while (star.size() && open.size()) {
            if (open.top() > star.top()) return false;
            open.pop();
            star.pop();
        }
        return open.size() == 0;
    }
};
