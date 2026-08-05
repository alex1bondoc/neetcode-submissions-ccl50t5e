class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char c : tasks) {
            count[c - 'A']++;
        }
        int maxf = *max_element(count.begin(), count.end());
        int cnt{};
        for (int num : count) {
            cnt += (maxf == num);
        }
        int time = (maxf - 1) * (n + 1) + cnt;
        return std::max(time, static_cast<int>(tasks.size()));
    }
};