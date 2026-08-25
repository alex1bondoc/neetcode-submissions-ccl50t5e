class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // 1. Inițializăm toate caracterele unice cu gradul 0
        for (const string& word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // 2. Construim graful comparând cuvinte adiacente
        int n = static_cast<int>(words.size());
        for (int i = 0; i < n - 1; ++i) {
            const string& a = words[i];
            const string& b = words[i + 1];
            int minLen = min(a.size(), b.size());
            int k = 0;

            while (k < minLen && a[k] == b[k]) {
                k++;
            }

            // Caz invalid: "abc" vine după "abcd"
            if (k == minLen && a.size() > b.size()) {
                return "";
            }

            // Adăugăm muchia dacă nu am ajuns la capăt
            if (k < minLen) {
                char u = a[k], v = b[k];
                if (!adj[u].contains(v)) {
                    adj[u].insert(v);
                    indegree[v]++;
                }
            }
        }

        queue<char> q;
        for (const auto& [node, in] : indegree) {
            if (in == 0) q.push(node);
        }
        string res{};
        while (q.size()) {
            auto node{q.front()};
            q.pop();
            res = res + node;
            cout << res << endl;
            for (const auto& nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }
        return res;
    }
};
