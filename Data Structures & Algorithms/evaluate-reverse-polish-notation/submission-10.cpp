class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        int sum{};
        for (const auto& token : tokens) {
            if (token == "+") {
                int x{st.top()};
                st.pop();
                int y{st.top()};
                st.pop();
                st.push(x + y);
            }
            else if (token == "-") {
                int x{st.top()};
                st.pop();
                int y{st.top()};
                st.pop();
                st.push(y - x);
            }
            else if (token == "*") {
                int x{st.top()};
                st.pop();
                int y{st.top()};
                st.pop();
                st.push(x * y);
            }
            else if (token == "/") {
                int x{st.top()};
                st.pop();
                int y{st.top()};
                st.pop();
                st.push(y / x);
            }
            else st.push(std::stoi(token));
        }
        return st.top();
    }
};
