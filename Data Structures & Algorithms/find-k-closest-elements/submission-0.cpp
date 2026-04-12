class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = k - 1;
        
        std::vector<int> res{arr.begin(), arr.begin() + k};
        for (right = k; right <  arr.size(); ++right) {
            left ++;
            if (std::abs(res[0] - x) > std::abs(arr[right] - x)){
                res = vector<int> (arr.begin() + left, arr.begin() + right + 1);
            }
        }
        return res;
    }
};