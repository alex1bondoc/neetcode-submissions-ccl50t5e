class Solution {
public:
    string longestPalindrome(string s) {
        int n{static_cast<int>(s.size())};
        int start{0}, length{1};
        for (int i{}; i < n; ++i) {
            int left{i}, right{i};
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (length < right - left + 1) {
                    start = left;
                    length = right - left + 1;
                }
                left --;
                right ++;
            }
            right = i + 1;
            left = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (length < right - left + 1) {
                    start = left;
                    length = right - left + 1;
                }
                left --;
                right ++;
            }
        }
        return s.substr(start, length);
    }

};
