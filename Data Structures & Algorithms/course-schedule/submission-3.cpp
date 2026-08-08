class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses);
        int counter{};
        for (const auto& pre : prerequisites) {
            in[pre[1]]++;
        }
        queue<int> q;
        for (int i{}; i < numCourses; ++i) {
            if (in[i] == 0) q.push(i);
        }
        while (q.size()) {
            counter++;
            int node{q.front()};
            q.pop();
            for (const auto& pre: prerequisites) {
                if (pre[0] == 0) {
                    in[pre[1]]--;
                    if (in[pre[1]] == 0) q.push(pre[1]);
                }
            }
        }
        if (counter == numCourses) return true;
        return false;
    }
};
