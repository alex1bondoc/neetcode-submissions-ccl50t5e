class Solution {
public:
    int numDistinct(string s, string t) {
        int n{static_cast<int>(s.size())}, m{static_cast<int>(t.size())};
        unordered_map<string, int> map{};

        auto back = [&](auto self, int i, int j){
            if (i == n && j == m) return 1;
            else if (i > n || j > m) return 0;
            int res{};
            string c{};
            c += to_string(i) + "," + to_string(j);
            if (map.contains(c)) {
                return map[c];
            }
            if (s[i] == t[j]) {
                res += self(self, i + 1, j + 1);
            }
            res += self(self, i + 1, j);
            map[c] = res;
            return res;
        }; 
        return back(back, 0, 0);
    }
};
