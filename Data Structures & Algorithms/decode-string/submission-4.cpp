class Solution {
public:
    string decodeString(string s) {
        vector<pair<int, string>> st;
        string solution;    
        st.push_back({0, ""});
        for (int i{}; i < s.length(); ++i) {
            char c = s[i];
            if (isNum(c)) {
                int cnt{};
                while (i < s.size() && isNum(c)) {
                    i ++;
                    cnt = cnt * 10 + (c - '0');
                    c = s[i];
                }
                st.push_back({cnt, ""});
            }
            else if (c == ']') {
                int cnt{st.back().first};
                string aux{st.back().second};
                st.pop_back();
                while (cnt) {
                    st.back().second += aux;
                    cnt --;
                }

            }
            else {
                st.back().second += c;
            }
        }
        return st[0].second;
    }

    bool isNum(const char a) {
        return a >= '0' && a <= '9';
    }
};