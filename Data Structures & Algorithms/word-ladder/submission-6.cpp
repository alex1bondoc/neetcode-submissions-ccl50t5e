class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        wordList.push_back(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        for (const auto& str : wordList) {
            for (const auto& str2 : wordList) {
                if (str == str2) continue;
                int i{};
                int cnt{};
                for (; i < str.size(); ++i) {
                    if (str[i] == str2[i]) cnt++;
                }
                if (cnt == str.size() - 1) {
                    adj[str].push_back(str2);

                }
            }
        } 
        // for (const auto p : adj) {
        //     // std::cout << p.first << endl;
        //     // for (auto x : p.second) {
        //     //     std::cout << x <<  " ";
        //     // }
        //     // std::cout << endl;
        // }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (q.size()) {
            auto [node, len] = q.front();
            // std::cout << node << " " << len << endl;
            if (node == endWord) return len;
            q.pop();
            for (const auto& nei : adj[node]) {
                if (visited.contains(nei)) continue;
                visited.insert(nei);
                q.push({nei, len + 1});
            }
        } 
        return 0;
    }
};
