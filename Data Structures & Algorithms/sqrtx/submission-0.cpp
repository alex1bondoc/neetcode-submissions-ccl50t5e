class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid < x) {
                left = mid + 1;
                ans = mid;
            }
            else {
                right =  mid - 1;
            }
        }
        return ans;
    }
};