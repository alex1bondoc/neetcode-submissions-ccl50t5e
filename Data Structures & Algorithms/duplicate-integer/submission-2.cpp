class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for (int& x : nums) {
            if (s.contains(x)) return true;
            s.insert(x);
        }
        return false;
    }
};