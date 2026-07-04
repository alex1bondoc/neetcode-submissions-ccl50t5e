class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index{0};
        for (int i{k}; i < arr.size(); ++i) {
            if (std::abs(arr[i] - x) < std::abs(arr[index] - x)) {
                index++;
            }

        }
        vector<int> solution(arr.begin() + index, arr.begin() + index + k);
        return solution;
    }
};