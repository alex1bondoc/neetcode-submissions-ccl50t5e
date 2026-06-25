class Solution {
public:
    string decodeString(string s) {
        std::vector<string> st;
        std::vector<int> st2;
        st.push_back("");
        for (int i{}; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                int cnt{};
                while (s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + (s[i] - '0');
                    i++;
                }
                st2.push_back(cnt);
                st.push_back("");
            }
            else if (s[i] == ']') {
                string aux{""};
                for (int j{0}; j < st2.back(); ++j) {
                    aux += st.back();
                }
                st.pop_back();
                st2.pop_back();
                st.back() = st.back() + aux;
            }   
            else {
                st.back() += s[i];
            }
        }
        return st.back();
    }
};