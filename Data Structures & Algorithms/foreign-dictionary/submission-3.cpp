#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> degree;

        // 1. Inițializăm toate caracterele unice cu gradul 0
        for (const string& word : words) {
            for (char c : word) {
                degree[c] = 0;
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
                    degree[v]++;
                }
            }
        }

        // 3. Coada pentru Sorteare Topologică (Kahn)
        queue<char> q;
        for (const auto& [node, deg] : degree) {
            if (deg == 0) {
                q.push(node);
            }
        }

        string res = "";
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            res += node;

            for (char neighbor : adj[node]) {
                degree[neighbor]--;
                if (degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. Dacă există un ciclu, nu putem sorta toate literele
        if (res.size() != degree.size()) {
            return "";
        }

        return res;
    }
};