class Solution {
public:
    string simplifyPath(string path) {
        std::vector<std::string> st;
        for (int i{}; i < path.size(); ++i) {
            char c{path[i]};
            if (c == '/') {
                std::string aux{""};
                int j{i + 1};
                for (; j < path.size() && path[j] != '/'; ++j) {
                    aux += path[j];
                }
                std::cout << aux << std::endl;
                if (aux == "." || aux == "") {
                }
                else if (aux == "..") {
                    if (!st.empty()) st.pop_back();
                }
                else {
                    st.push_back(aux);
                }
                i = j - 1;
            }
        }
        std::reverse(st.begin(), st.end());
        std::string sol{"/"};
        int i{0};
        while (st.size()) {
            if (i != 0)sol += "/";
            sol += st.back();
            st.pop_back();
            i++;
        }
        return sol;
    }
};