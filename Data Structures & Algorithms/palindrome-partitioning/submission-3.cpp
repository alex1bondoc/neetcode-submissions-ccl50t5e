class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        back(cur, s, 0);
        return res;
    }
    void back(vector<string> cur, string& s, int k) {
        if (k == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int i{1}; i <= s.size() - k; ++i) {
            std::cout << s.substr(k, i) << endl;
            if (isPalindrome(s.substr(k, i))) {
                cur.push_back(s.substr(k, i));
                back(cur, s, k + i);
                cur.pop_back();
            }
        }

    }

    bool isPalindrome(string s) {
        int l{}, r{static_cast<int>(s.size() - 1)};
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
