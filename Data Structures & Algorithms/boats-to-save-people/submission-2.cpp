class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int boat = 0;
        int sol{};
        while (left <= right) {
            if (people[left] < people[right]) {
                if (boat + people[left] <= limit)
                    boat += people[right];
                else {
                    sol++;
                    boat = people[left];
                }
                left ++;
            }
            else {
                if (boat + people[right] <= limit)
                    boat += people[right];
                else {
                    sol++;
                    boat = people[right];
                }
                right --;
            }
        }
        return sol;
    }
};