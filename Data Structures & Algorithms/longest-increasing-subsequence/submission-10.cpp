class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        std::vector<int> dp;
        for(int i = 0; i < nums.size(); ++i) {
            // Dacă nums[i] e mai mare decât cel mai mare element, extindem LIS
            if (dp.empty() || dp.back() < nums[i]){
                dp.push_back(nums[i]);
            } else {
                // Altfel, căutăm binar PRIMUL element >= nums[i]
                int l = 0, r = dp.size() - 1;
                int pos = 0;
                while (l <= r){
                    int mid = l + (r - l) / 2;
                    if (dp[mid] >= nums[i]) {
                        pos = mid;    // Acesta e un candidat
                        r = mid - 1;  // Mergem spre stânga să găsim cel mai mic index
                    } else {
                        l = mid + 1;  // Prea mic, mergem spre dreapta
                    }
                }
                dp[pos] = nums[i]; // Înlocuim pentru a menține valorile cât mai mici
            }
        }
        return dp.size();
    }
};