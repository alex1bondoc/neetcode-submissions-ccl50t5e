class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x{}, y{}, z{};
        for (const auto& triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) 
                continue;
            if (triplet[0] == target[0]) x = true;
            if (triplet[1] == target[1]) y = true;
            if (triplet[2] == target[2]) z = true;
        }
        return x && y && z;
    }
};
