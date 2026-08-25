#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = static_cast<int>(hand.size());
        if (n % groupSize != 0) return false;
        if (groupSize == 1) return true;

        // Frecvență directă deoarece valorile sunt între 0 și 1000
        vector<int> count(1002, 0);
        int mini = 1000, maxi = 0;

        for (int card : hand) {
            count[card]++;
            mini = min(mini, card);
            maxi = max(maxi, card);
        }

        for (int i = mini; i <= maxi; ++i) {
            if (count[i] > 0) {
                int needed = count[i];
                // Dacă grupul depășește limita superioară
                if (i + groupSize - 1 > 1000) return false;

                // Scădem 'needed' din toate cărțile consecutive dintr-un singur pas
                for (int j = 0; j < groupSize; ++j) {
                    if (count[i + j] < needed) {
                        return false;
                    }
                    count[i + j] -= needed;
                }
            }
        }

        return true;
    }
};