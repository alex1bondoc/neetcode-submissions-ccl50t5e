class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto& str : strs) {
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        int cnt = 0;
        int i = 0;
        std::vector<string> res;
        while (i < s.size()) {
            cnt = 10 * cnt + (s[i] -'0');
            i ++;
            if (s[i] == '#' ) {
                res.push_back(s.substr(i + 1, cnt));
                i = i + 1 + cnt;
                cnt = 0;
            }
        }
        return res;
    }
};
