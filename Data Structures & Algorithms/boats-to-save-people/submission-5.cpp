class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int sol{};
        std::sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        while (left < right) {
            int boat{people[right]};
            right --;
            if (boat + people[left] < limit) {
                left ++;
            }
            sol ++;
        }
        return sol;
    }
};