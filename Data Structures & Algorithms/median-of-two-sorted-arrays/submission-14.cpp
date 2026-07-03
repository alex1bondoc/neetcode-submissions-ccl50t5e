class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) 
            std::swap(nums1, nums2);
        int n{static_cast<int>(nums1.size())};
        int m{static_cast<int>(nums2.size())};
        int left{};
        int right{n};

        while (left <= right) {
            int mid{left + (right - left) / 2};
            int takeFromFirst{mid};
            int takeFromSecond{(n + m) / 2 - mid};
            int max1{(takeFromFirst == 0) ? INT_MIN : nums1[takeFromFirst - 1]};
            int max2{(takeFromSecond == 0) ? INT_MIN : nums2[takeFromSecond - 1]};
            int min1{(takeFromFirst == n) ? INT_MAX : nums1[takeFromFirst]};
            int min2{(takeFromSecond >= m) ? INT_MAX : nums2[takeFromSecond]};
            if (max1 <= min2 && max2 <= min1) {
                if ((n + m ) % 2) {
                    return std::min(min1, min2);
                }
                else {
                    return ((std::max(max1, max2) + std::min(min1, min2)) / 2.0);
                }
            }
            else if (max1 > min2) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
