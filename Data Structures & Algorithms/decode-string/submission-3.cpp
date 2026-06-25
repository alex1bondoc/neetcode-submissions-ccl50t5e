class Solution {
public:
    string decodeString(string s) {
        std::stack<char> st;

        for (char c : s) {
            if (c == ']') {
                string aux = "";
                while (st.top() != '[') {
                    aux = st.top() + aux;
                    st.pop();
                }
                st.pop(); 

                int cnt = 0, pow = 1;
                while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
                    cnt = cnt + pow * (st.top() - '0');
                    pow *= 10;
                    st.pop();
                }

                string multiplied = "";
                while (cnt > 0) {
                    multiplied += aux;
                    cnt--;
                }
                
                for (char ch : multiplied) {
                    st.push(ch);
                }
            }
            else {
                st.push(c);
            }
        }

        string sol = "";
        while (!st.empty()) {
            sol = st.top() + sol;
            st.pop();
        }
        
        return sol;
    }
};