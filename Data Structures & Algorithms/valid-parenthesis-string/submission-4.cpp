class Solution {
public:
    bool checkValidString(string s) {
        std::stack<int> open{};
        std::stack<int> star{};
        int i = 0;
        for (char c : s) {
            if (c == '('){
                open.push(i);
            }
            else if (c == '*'){
                star.push(i);
            }
            else {
                if (open.empty() && star.empty()) return false;
                if (!open.empty()) open.pop();
                else star.pop();
            }
            i++;
        }
        while (!open.empty() && !star.empty()) {
            if (open.top() >  star.top())
                return false;
            open.pop();
            star.pop();
        }
        return open.empty();
    }
};
