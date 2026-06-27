class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        for (int i{}; i < path.size(); ++i) {
            int j{i + 1};
            string aux{};
            while (j < path.size() && path[j] != '/') {
                aux += path[j];
                j ++;
            }
            if (aux == "..") {
                if (st.size())
                    st.pop_back();
            }
            else if (!aux.empty() && aux != ".") {
                st.push_back(aux);
            }
            i = j - 1;
        }
        string sol{"/"};
        for (int i{}; i < st.size(); ++i) {
            if (i != 0) sol += "/";
            sol += st[i];
        }
        return sol;
    }
};