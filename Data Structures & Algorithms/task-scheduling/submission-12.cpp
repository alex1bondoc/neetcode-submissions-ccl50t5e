class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxi{};
        int apps{};
        std::vector<int> map(26, 0);
        for (char c : tasks) {
            map[c - 'A'] ++;
            std::cout <<map[c - 'A'] <<" " << maxi <<endl;
            if (map[c - 'A'] >  maxi) {
                maxi = map[c - 'A'];
                apps = 1;
            }
            else if(map[c - 'A'] == maxi){
                apps ++;
            }
        std::cout<< maxi << " " << apps<<endl;

        }
        return std::max((int)tasks.size(), (maxi - 1) * (n + 1) + apps);
    }
};
