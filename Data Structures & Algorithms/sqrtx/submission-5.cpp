class Solution {
public:
    int mySqrt(int x){
        int sol {};
        int left{};
        int right{x - 1};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            if (mid * mid <= x) {
                sol = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return sol;
    }
};