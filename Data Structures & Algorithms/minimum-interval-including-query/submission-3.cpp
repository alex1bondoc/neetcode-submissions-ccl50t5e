#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // 1. Sortăm intervalele după timpul de start
        sort(intervals.begin(), intervals.end());

        // 2. Sortăm o copie a query-urilor
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        // Min-Heap: {lungime, end}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        unordered_map<int, int> resMap;

        int i = 0;
        int n = intervals.size();

        for (int q : sortedQueries) {
            while (i < n && intervals[i][0] <= q) {
                minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while (minHeap.size() && minHeap.top().second < q) {
                minHeap.pop();
            }
            resMap[q] = minHeap.empty() ? -1 : minHeap.top().first;
        }

        // 3. Reconstituim răspunsurile în ordinea inițială a query-urilor
        vector<int> res;
        for (int q : queries) {
            res.push_back(resMap[q]);
        }
        return res;
    }
};