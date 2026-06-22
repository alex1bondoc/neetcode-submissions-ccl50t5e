class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int boat = 0;
        int sol{};
        while (left <= right) {
            int remain = limit - people[right --];
            sol ++;
            if (left <= right && remain >= people[left]) {
                left ++;
            }
        }
        return sol;
    }
};