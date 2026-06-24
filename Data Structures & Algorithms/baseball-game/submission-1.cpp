class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> st;
        for (const auto& op : operations) {
            if (op == "+") {
                int x{st.top()};
                st.pop();
                int y{st.top()};
                st.pop();
                st.push(y);
                st.push(x);
                st.push(x + y);
            }
            else if (op == "D") {
                int x{st.top()};
                st.push(x * 2);
            }
            else if (op == "C") {
                st.pop();
            }
            else {
                st.push(stoi(op));
            }
        }
        int sol{};

        while (st.size() > 0) {
            sol += st.top();
            st.pop();
        }
        return sol;
    }
};