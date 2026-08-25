class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        unordered_map<int, int> map;
        int mini{1 << 30};
        int maxi{};
        for (int card : hand) {
            map[card] ++;
            mini = min(card, mini);
            maxi = max(card, maxi);
        }
        for (int i{mini}; i <= maxi - groupSize + 1;) {
            bool found{true};
            for (int j{}; j < groupSize; j++){
                if (!map.contains(i + j)) {
                    found = false;
                    break;
                } 
                map[i + j] --;
                if (map[i + j] == 0) map.erase(i + j);
            }
            if (!found && !map.contains(i - 1)) return false;
            if (!map.contains(i)) i++; 
        }
        return map.size() == 0;

    }
};
