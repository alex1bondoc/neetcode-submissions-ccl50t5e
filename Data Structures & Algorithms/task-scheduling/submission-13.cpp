class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxi{};
        int apps{};
        std::vector<int> map(26, 0);
        for (char task:tasks) {
            map[task - 'A']++;
            int aux = map[task- 'A'];
            if (aux >  maxi) {
                maxi = aux;
                apps = 1;
            }
            else if( aux == maxi) {
                apps += 1;
            }
        }
        std::cout<< maxi << " " << apps;
        int m = tasks.size();
        return std::max(m, (maxi - 1) * (n + 1) + apps);
    }
};
