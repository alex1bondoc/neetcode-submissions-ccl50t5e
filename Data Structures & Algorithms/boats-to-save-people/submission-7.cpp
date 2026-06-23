class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int maxi{0}, mini{300001};
        std::unordered_map<int, int> counter;
        for (const auto& p : people) {
            maxi = std::max(maxi, p);
            mini = std::min(mini, p);
            counter[p] ++;
        }
        int right = maxi;
        int left = mini;
        int sol{};
        while (left <= right) {
            int boat{right};
            counter[right]--;
            while (counter[right] == 0 && left <= right) right --;
            if (boat + left <= limit) {
                counter[left]--;
                while (counter[left] == 0 && left <= right) left ++;
            }
            sol ++;
        }
        return sol;
    }
};